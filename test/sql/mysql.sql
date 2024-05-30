SELECT tbl_dataqueries.id AS `id`, 
tbl_dataqueries.created_at AS `created_at`, 
tbl_dataqueries.updated_at AS `updated_at`, 
tbl_dataqueries.name AS `name`, 
tbl_dataqueries.category AS `category`, 
tbl_dataqueries.content AS `content`, 
tbl_dataqueries.desc AS `desc`, 
tbl_dataqueries.tenant_id AS `tenant_id`, 
tbl_dataqueries.datasource_id AS `datasource_id`, 
tbl_datasources.name AS `datasource_name` 
FROM tbl_dataqueries 
LEFT JOIN tbl_datasources ON tbl_datasources.id = tbl_dataqueries.datasource_id 
WHERE tbl_dataqueries.deleted_at IS NULL 
AND tbl_dataqueries.tenant_id IN (9) 
ORDER BY created_at DESC LIMIT 10 OFFSET 0


SELECT   
`shop_4_test.id`  ,  
`shop_4_test.click`  ,  
`shop_4_test.register`  , 
`shop_4_test.shopcar`  ,  
`shop_4_test.order`,    
ABS  (  `gdp_10_years.value`  )  AS  `放大法`  
FROM  
(  SELECT `shop_4_test`.`id` AS `shop_4_test.id`, 
        `shop_4_test`.`click` AS `shop_4_test.click`, 
        `shop_4_test`.`register` AS `shop_4_test.register`, 
        `shop_4_test`.`shopcar` AS `shop_4_test.shopcar`, 
        `shop_4_test`.`order` AS `shop_4_test.order` 
FROM 
(SELECT id AS `id`, 
click AS `click`, 
register AS `register`, 
shopcar AS `shopcar`, 
order AS `order` FROM shop_4_test) AS shop_4_test    )  t 
LIMIT 32


WITH sales_summary AS (
  SELECT
    product_id,
    customer_id,
    SUM(quantity) AS total_quantity,
    SUM(price * quantity) AS total_sales,
    AVG(price) AS avg_price,
    COUNT(*) AS total_orders
  FROM sales
  WHERE order_date BETWEEN '2021-01-01' AND '2021-12-31'
  GROUP BY product_id, customer_id
),
ranked_customers AS (
  SELECT
    customer_id,
    product_id,
    total_quantity,
    total_sales,
    avg_price,
    total_orders,
    RANK() OVER (PARTITION BY product_id ORDER BY total_sales DESC) AS sales_rank
  FROM sales_summary
)
SELECT
  p.product_name,
  c.customer_name,
  rc.total_quantity,
  rc.total_sales,
  rc.avg_price,
  rc.total_orders,
  rc.sales_rank
FROM ranked_customers rc
JOIN products p ON rc.product_id = p.product_id
JOIN customers c ON rc.customer_id = c.customer_id
WHERE rc.sales_rank <= 3
ORDER BY p.product_name, rc.sales_rank;

-- 这个查询的目的是找出在 2021 年销售额排名前三的客户，以及他们购买的产品。查询首先使用 `WITH` 子句创建了一个名为 `sales_summary` 的临时表，该表包含每个产品和客户的总销售量、总销售额、平均价格和订单数量。然后，使用 `RANK()` 窗口函数为每个产品的客户按销售额降序排名，并将结果存储在名为 `ranked_customers` 的另一个临时表中。

-- 最后，查询将 `ranked_customers` 与 `products` 和 `customers` 表连接，以获取产品名称和客户名称，并筛选出排名前三的客户。查询结果按产品名称和销售排名进行排序。

-- 这个查询展示了 SQL 的强大功能，包括复杂的表连接、聚合函数和窗口函数的使用。在实际应用中，类似的查询可以用于分析销售数据、客户行为等多种场景。