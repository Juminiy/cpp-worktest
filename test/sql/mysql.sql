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
