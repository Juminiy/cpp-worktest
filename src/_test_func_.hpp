#pragma once 
#ifndef _TEST_FUNC_HPP
#define _TEST_FUNC_HPP

#define INPUT_FILE "../test/static-file/input.txt"
#define OUTPUT_FILE "../test/static-file/output.txt"    
#define WORLD_CAPITALS "../test/static-file/world-capital.txt"
#define SIZE_OF_TYPE_PREFIX "../test/static-file/type-info"


void TestReadWriteFile();

void TestBoolAlpha();

void TestReadLines();

void TestCinAteN();

void TestOSS();

int Capitals(int const &);

void TestHasHexLetters_3_version_pat(int const &);

void DrawTriangle(int const&);

void TestInRange(int const &);

void TestInRangeV2(int const &);

#endif 