/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(PiezasTest, placepiece)
{
	Piezas test;
	Piece cap;
	cap = test.dropPiece(2);
	ASSERT_TRUE(cap == X);
}

TEST(PiezasTest, getpiece)
{
	Piezas test;
	Piece cap;
	test.dropPiece(2);
	test.dropPiece(2);
	test.dropPiece(2);
	cap = test.pieceAt(1,2);
	ASSERT_TRUE(cap == O);
}
TEST(PiezasTest, placepieceoutbounds)
{
	Piezas test;
	Piece cap;
	cap = test.dropPiece(4);
	test.dropPiece(5);
	test.dropPiece(-1);
	ASSERT_TRUE(cap == Invalid);
	ASSERT_TRUE(test.dropPiece(0) == O);
}
TEST(PiezasTest, placepiecefull)
{
	Piezas test;
	Piece cap;
	test.dropPiece(2);
	test.dropPiece(2);
	test.dropPiece(2);
	test.dropPiece(2);
	cap = test.dropPiece(2);
	ASSERT_TRUE(cap == Blank);
}

TEST(PiezasTest, getpieceinvalid)
{
	Piezas test;
	Piece cap;
	cap = test.pieceAt(3,2);
	ASSERT_TRUE(cap == Invalid);
}
TEST(PiezasTest, resetboard)
{
	Piezas test;
	Piece cap;
	test.dropPiece(2);
	test.dropPiece(2);
	test.dropPiece(2);
	test.reset();
	cap = test.pieceAt(1,2);
	ASSERT_TRUE(cap == Blank);
}

TEST(PiezasTest, gamestatenotdone)
{
	Piezas test;
	test.dropPiece(0);
	test.dropPiece(1);
	ASSERT_TRUE(test.gameState() == Invalid);
}

TEST(PiezasTest, gamestatecountrows)
{
	Piezas test;
	test.dropPiece(0);//x
	test.dropPiece(0);//o
	test.dropPiece(1);//x
	test.dropPiece(0);
	test.dropPiece(2);//x
	test.dropPiece(1);
	test.dropPiece(3);//x
	test.dropPiece(1);
	test.dropPiece(3);//x
	test.dropPiece(2);
	test.dropPiece(2);//x
	test.dropPiece(3);
	ASSERT_EQ(test.gameState(),  X);
}






TEST(PiezasTest, gamestatecountcols)
{
	Piezas test;
	test.dropPiece(1);//x
	test.dropPiece(0);//o
	test.dropPiece(3);//x
	test.dropPiece(0);
	test.dropPiece(1);//x
	test.dropPiece(2);
	test.dropPiece(2);//x
	test.dropPiece(0);
	test.dropPiece(2);//x
	test.dropPiece(3);
	test.dropPiece(3);//x
	test.dropPiece(1);
	ASSERT_EQ(test.gameState(), O);
}

TEST(PiezasTest, gamestatetie)
{
	Piezas test;
	test.dropPiece(1);//x
	test.dropPiece(0);//o
	test.dropPiece(3);//x
	test.dropPiece(0);
	test.dropPiece(1);//x
	test.dropPiece(2);
	test.dropPiece(2);//x
	test.dropPiece(0);
	test.dropPiece(1);//x
	test.dropPiece(3);
	test.dropPiece(3);//x
	test.dropPiece(2);
	ASSERT_EQ(test.gameState(), Blank);
}


