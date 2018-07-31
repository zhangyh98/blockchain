#include "gtest/gtest.h"
#include "common/general.h"

/*
total reward is five hundred million, decreasing 1/4 each year.
the reward for first periord: 1.25 hundred million£¬ 125,000,000 BU COIN
a block per 10 seconds, 3153600 blocks per year, five years: 3153600 * 5 = 15768000 block

reward per block: 125,000,000  / 15768000 = 7.927447995941147

the process of inferencing for the reward of first periord:
8 bu per block, 8 * 3153600 * 5  = 126144000
*/
class decrement_value_utest : public testing::Test
{
protected:

    // Sets up the test fixture.
    virtual void SetUp()
    {
    }

    // Tears down the test fixture.
    virtual void TearDown()
    {

    }

protected:
    void UT_Calc_Block_Decrement_Vaule();
};

TEST_F(decrement_value_utest, UT_Calc_Block_Decrement_Vaule){ UT_Calc_Block_Decrement_Vaule(); }
void decrement_value_utest::UT_Calc_Block_Decrement_Vaule()
{
	//±ê×¼ÓÃÀý
	EXPECT_EQ(chain::GetBlockReward(0 * chain::General::REWARD_PERIOD), 800000000);
	EXPECT_EQ(chain::GetBlockReward(1 * chain::General::REWARD_PERIOD - 1), 800000000);
	EXPECT_EQ(chain::GetBlockReward(1 * chain::General::REWARD_PERIOD), 600000000);
	EXPECT_EQ(chain::GetBlockReward(1 * chain::General::REWARD_PERIOD + 1), 600000000);

	EXPECT_EQ(chain::GetBlockReward(2 * chain::General::REWARD_PERIOD - 1), 600000000);
	EXPECT_EQ(chain::GetBlockReward(2 * chain::General::REWARD_PERIOD), 450000000);
	EXPECT_EQ(chain::GetBlockReward(2 * chain::General::REWARD_PERIOD + 1), 450000000);

	EXPECT_EQ(chain::GetBlockReward(3 * chain::General::REWARD_PERIOD - 1), 450000000);
	EXPECT_EQ(chain::GetBlockReward(3 * chain::General::REWARD_PERIOD), 337500000);
	EXPECT_EQ(chain::GetBlockReward(3 * chain::General::REWARD_PERIOD + 1), 337500000);

	EXPECT_EQ(chain::GetBlockReward(4 * chain::General::REWARD_PERIOD - 1), 337500000);
	EXPECT_EQ(chain::GetBlockReward(4 * chain::General::REWARD_PERIOD), 253125000);
	EXPECT_EQ(chain::GetBlockReward(4 * chain::General::REWARD_PERIOD + 1), 253125000);

	EXPECT_EQ(chain::GetBlockReward(5 * chain::General::REWARD_PERIOD - 1), 253125000);
	EXPECT_EQ(chain::GetBlockReward(5 * chain::General::REWARD_PERIOD), 189843750);
	EXPECT_EQ(chain::GetBlockReward(5 * chain::General::REWARD_PERIOD + 1), 189843750);

	EXPECT_EQ(chain::GetBlockReward(6 * chain::General::REWARD_PERIOD - 1), 189843750);
	EXPECT_EQ(chain::GetBlockReward(6 * chain::General::REWARD_PERIOD), 142382813);
	EXPECT_EQ(chain::GetBlockReward(6 * chain::General::REWARD_PERIOD + 1), 142382813);

	EXPECT_EQ(chain::GetBlockReward(7 * chain::General::REWARD_PERIOD - 1), 142382813);
	EXPECT_EQ(chain::GetBlockReward(7 * chain::General::REWARD_PERIOD), 106787110);
	EXPECT_EQ(chain::GetBlockReward(7 * chain::General::REWARD_PERIOD + 1), 106787110);

	EXPECT_EQ(chain::GetBlockReward(8 * chain::General::REWARD_PERIOD - 1), 106787110);
	EXPECT_EQ(chain::GetBlockReward(8 * chain::General::REWARD_PERIOD), 80090333);
	EXPECT_EQ(chain::GetBlockReward(8 * chain::General::REWARD_PERIOD + 1), 80090333);

	EXPECT_EQ(chain::GetBlockReward(9 * chain::General::REWARD_PERIOD - 1), 80090333);
	EXPECT_EQ(chain::GetBlockReward(9 * chain::General::REWARD_PERIOD), 60067750);
	EXPECT_EQ(chain::GetBlockReward(9 * chain::General::REWARD_PERIOD + 1), 60067750);

	EXPECT_EQ(chain::GetBlockReward(10 * chain::General::REWARD_PERIOD - 1), 60067750);
	EXPECT_EQ(chain::GetBlockReward(10 * chain::General::REWARD_PERIOD), 45050813);
	EXPECT_EQ(chain::GetBlockReward(10 * chain::General::REWARD_PERIOD + 1), 45050813);

	EXPECT_EQ(chain::GetBlockReward(11 * chain::General::REWARD_PERIOD - 1), 45050813);
	EXPECT_EQ(chain::GetBlockReward(11 * chain::General::REWARD_PERIOD), 33788110);
	EXPECT_EQ(chain::GetBlockReward(11 * chain::General::REWARD_PERIOD + 1), 33788110);

	EXPECT_EQ(chain::GetBlockReward(12 * chain::General::REWARD_PERIOD - 1), 33788110);
	EXPECT_EQ(chain::GetBlockReward(12 * chain::General::REWARD_PERIOD), 25341083);
	EXPECT_EQ(chain::GetBlockReward(12 * chain::General::REWARD_PERIOD + 1), 25341083);

	EXPECT_EQ(chain::GetBlockReward(13 * chain::General::REWARD_PERIOD - 1), 25341083);
	EXPECT_EQ(chain::GetBlockReward(13 * chain::General::REWARD_PERIOD), 19005813);
	EXPECT_EQ(chain::GetBlockReward(13 * chain::General::REWARD_PERIOD + 1), 19005813);

	EXPECT_EQ(chain::GetBlockReward(14 * chain::General::REWARD_PERIOD - 1), 19005813);
	EXPECT_EQ(chain::GetBlockReward(14 * chain::General::REWARD_PERIOD), 14254360);
	EXPECT_EQ(chain::GetBlockReward(14 * chain::General::REWARD_PERIOD + 1), 14254360);

	EXPECT_EQ(chain::GetBlockReward(15 * chain::General::REWARD_PERIOD - 1), 14254360);
	EXPECT_EQ(chain::GetBlockReward(15 * chain::General::REWARD_PERIOD), 10690770);
	EXPECT_EQ(chain::GetBlockReward(15 * chain::General::REWARD_PERIOD + 1), 10690770);

	EXPECT_EQ(chain::GetBlockReward(16 * chain::General::REWARD_PERIOD - 1), 10690770);
	EXPECT_EQ(chain::GetBlockReward(16 * chain::General::REWARD_PERIOD), 8018078);
	EXPECT_EQ(chain::GetBlockReward(16 * chain::General::REWARD_PERIOD + 1), 8018078);


	EXPECT_EQ(chain::GetBlockReward(16 * chain::General::REWARD_PERIOD - 1), 10690770);
	EXPECT_EQ(chain::GetBlockReward(16 * chain::General::REWARD_PERIOD), 8018078);
	EXPECT_EQ(chain::GetBlockReward(16 * chain::General::REWARD_PERIOD + 1), 8018078);


	EXPECT_EQ(chain::GetBlockReward(17 * chain::General::REWARD_PERIOD - 1), 8018078);
	EXPECT_EQ(chain::GetBlockReward(17 * chain::General::REWARD_PERIOD), 6013559);
	EXPECT_EQ(chain::GetBlockReward(17 * chain::General::REWARD_PERIOD + 1), 6013559);


	EXPECT_EQ(chain::GetBlockReward(18 * chain::General::REWARD_PERIOD - 1), 6013559);
	EXPECT_EQ(chain::GetBlockReward(18 * chain::General::REWARD_PERIOD), 4510170);
	EXPECT_EQ(chain::GetBlockReward(18 * chain::General::REWARD_PERIOD + 1), 4510170);


	EXPECT_EQ(chain::GetBlockReward(19 * chain::General::REWARD_PERIOD - 1), 4510170);
	EXPECT_EQ(chain::GetBlockReward(19 * chain::General::REWARD_PERIOD), 3382628);
	EXPECT_EQ(chain::GetBlockReward(19 * chain::General::REWARD_PERIOD + 1), 3382628);


	EXPECT_EQ(chain::GetBlockReward(20 * chain::General::REWARD_PERIOD - 1), 3382628);
	EXPECT_EQ(chain::GetBlockReward(20 * chain::General::REWARD_PERIOD), 2536971);
	EXPECT_EQ(chain::GetBlockReward(20 * chain::General::REWARD_PERIOD + 1), 2536971);


	EXPECT_EQ(chain::GetBlockReward(21 * chain::General::REWARD_PERIOD - 1), 2536971);
	EXPECT_EQ(chain::GetBlockReward(21 * chain::General::REWARD_PERIOD), 1902729);
	EXPECT_EQ(chain::GetBlockReward(21 * chain::General::REWARD_PERIOD + 1), 1902729);


	EXPECT_EQ(chain::GetBlockReward(22 * chain::General::REWARD_PERIOD - 1), 1902729);
	EXPECT_EQ(chain::GetBlockReward(22 * chain::General::REWARD_PERIOD), 1427047);
	EXPECT_EQ(chain::GetBlockReward(22 * chain::General::REWARD_PERIOD + 1), 1427047);


	EXPECT_EQ(chain::GetBlockReward(23 * chain::General::REWARD_PERIOD - 1), 1427047);
	EXPECT_EQ(chain::GetBlockReward(23 * chain::General::REWARD_PERIOD), 1070286);
	EXPECT_EQ(chain::GetBlockReward(23 * chain::General::REWARD_PERIOD + 1), 1070286);


	EXPECT_EQ(chain::GetBlockReward(24 * chain::General::REWARD_PERIOD - 1), 1070286);
	EXPECT_EQ(chain::GetBlockReward(24 * chain::General::REWARD_PERIOD), 802715);
	EXPECT_EQ(chain::GetBlockReward(24 * chain::General::REWARD_PERIOD + 1), 802715);


	EXPECT_EQ(chain::GetBlockReward(25 * chain::General::REWARD_PERIOD - 1), 802715);
	EXPECT_EQ(chain::GetBlockReward(25 * chain::General::REWARD_PERIOD), 602037);
	EXPECT_EQ(chain::GetBlockReward(25 * chain::General::REWARD_PERIOD + 1), 602037);


	EXPECT_EQ(chain::GetBlockReward(26 * chain::General::REWARD_PERIOD - 1), 602037);
	EXPECT_EQ(chain::GetBlockReward(26 * chain::General::REWARD_PERIOD), 451528);
	EXPECT_EQ(chain::GetBlockReward(26 * chain::General::REWARD_PERIOD + 1), 451528);


	EXPECT_EQ(chain::GetBlockReward(27 * chain::General::REWARD_PERIOD - 1), 451528);
	EXPECT_EQ(chain::GetBlockReward(27 * chain::General::REWARD_PERIOD), 338646);
	EXPECT_EQ(chain::GetBlockReward(27 * chain::General::REWARD_PERIOD + 1), 338646);


	EXPECT_EQ(chain::GetBlockReward(28 * chain::General::REWARD_PERIOD - 1), 338646);
	EXPECT_EQ(chain::GetBlockReward(28 * chain::General::REWARD_PERIOD), 253985);
	EXPECT_EQ(chain::GetBlockReward(28 * chain::General::REWARD_PERIOD + 1), 253985);


	EXPECT_EQ(chain::GetBlockReward(29 * chain::General::REWARD_PERIOD - 1), 253985);
	EXPECT_EQ(chain::GetBlockReward(29 * chain::General::REWARD_PERIOD), 190489);
	EXPECT_EQ(chain::GetBlockReward(29 * chain::General::REWARD_PERIOD + 1), 190489);


	EXPECT_EQ(chain::GetBlockReward(30 * chain::General::REWARD_PERIOD - 1), 190489);
	EXPECT_EQ(chain::GetBlockReward(30 * chain::General::REWARD_PERIOD), 142867);
	EXPECT_EQ(chain::GetBlockReward(30 * chain::General::REWARD_PERIOD + 1), 142867);


	EXPECT_EQ(chain::GetBlockReward(31 * chain::General::REWARD_PERIOD - 1), 142867);
	EXPECT_EQ(chain::GetBlockReward(31 * chain::General::REWARD_PERIOD), 107151);
	EXPECT_EQ(chain::GetBlockReward(31 * chain::General::REWARD_PERIOD + 1), 107151);


	EXPECT_EQ(chain::GetBlockReward(32 * chain::General::REWARD_PERIOD - 1), 107151);
	EXPECT_EQ(chain::GetBlockReward(32 * chain::General::REWARD_PERIOD), 80364);
	EXPECT_EQ(chain::GetBlockReward(32 * chain::General::REWARD_PERIOD + 1), 80364);


	EXPECT_EQ(chain::GetBlockReward(33 * chain::General::REWARD_PERIOD - 1), 80364);
	EXPECT_EQ(chain::GetBlockReward(33 * chain::General::REWARD_PERIOD), 60273);
	EXPECT_EQ(chain::GetBlockReward(33 * chain::General::REWARD_PERIOD + 1), 60273);


	EXPECT_EQ(chain::GetBlockReward(34 * chain::General::REWARD_PERIOD - 1), 60273);
	EXPECT_EQ(chain::GetBlockReward(34 * chain::General::REWARD_PERIOD), 45205);
	EXPECT_EQ(chain::GetBlockReward(34 * chain::General::REWARD_PERIOD + 1), 45205);


	EXPECT_EQ(chain::GetBlockReward(35 * chain::General::REWARD_PERIOD - 1), 45205);
	EXPECT_EQ(chain::GetBlockReward(35 * chain::General::REWARD_PERIOD), 33904);
	EXPECT_EQ(chain::GetBlockReward(35 * chain::General::REWARD_PERIOD + 1), 33904);


	EXPECT_EQ(chain::GetBlockReward(36 * chain::General::REWARD_PERIOD - 1), 33904);
	EXPECT_EQ(chain::GetBlockReward(36 * chain::General::REWARD_PERIOD), 25428);
	EXPECT_EQ(chain::GetBlockReward(36 * chain::General::REWARD_PERIOD + 1), 25428);


	EXPECT_EQ(chain::GetBlockReward(37 * chain::General::REWARD_PERIOD - 1), 25428);
	EXPECT_EQ(chain::GetBlockReward(37 * chain::General::REWARD_PERIOD), 19071);
	EXPECT_EQ(chain::GetBlockReward(37 * chain::General::REWARD_PERIOD + 1), 19071);


	EXPECT_EQ(chain::GetBlockReward(38 * chain::General::REWARD_PERIOD - 1), 19071);
	EXPECT_EQ(chain::GetBlockReward(38 * chain::General::REWARD_PERIOD), 14304);
	EXPECT_EQ(chain::GetBlockReward(38 * chain::General::REWARD_PERIOD + 1), 14304);


	EXPECT_EQ(chain::GetBlockReward(39 * chain::General::REWARD_PERIOD - 1), 14304);
	EXPECT_EQ(chain::GetBlockReward(39 * chain::General::REWARD_PERIOD), 10728);
	EXPECT_EQ(chain::GetBlockReward(39 * chain::General::REWARD_PERIOD + 1), 10728);


	EXPECT_EQ(chain::GetBlockReward(40 * chain::General::REWARD_PERIOD - 1), 10728);
	EXPECT_EQ(chain::GetBlockReward(40 * chain::General::REWARD_PERIOD), 8046);
	EXPECT_EQ(chain::GetBlockReward(40 * chain::General::REWARD_PERIOD + 1), 8046);


	EXPECT_EQ(chain::GetBlockReward(41 * chain::General::REWARD_PERIOD - 1), 8046);
	EXPECT_EQ(chain::GetBlockReward(41 * chain::General::REWARD_PERIOD), 6035);
	EXPECT_EQ(chain::GetBlockReward(41 * chain::General::REWARD_PERIOD + 1), 6035);


	EXPECT_EQ(chain::GetBlockReward(42 * chain::General::REWARD_PERIOD - 1), 6035);
	EXPECT_EQ(chain::GetBlockReward(42 * chain::General::REWARD_PERIOD), 4527);
	EXPECT_EQ(chain::GetBlockReward(42 * chain::General::REWARD_PERIOD + 1), 4527);


	EXPECT_EQ(chain::GetBlockReward(43 * chain::General::REWARD_PERIOD - 1), 4527);
	EXPECT_EQ(chain::GetBlockReward(43 * chain::General::REWARD_PERIOD), 3396);
	EXPECT_EQ(chain::GetBlockReward(43 * chain::General::REWARD_PERIOD + 1), 3396);


	EXPECT_EQ(chain::GetBlockReward(44 * chain::General::REWARD_PERIOD - 1), 3396);
	EXPECT_EQ(chain::GetBlockReward(44 * chain::General::REWARD_PERIOD), 2547);
	EXPECT_EQ(chain::GetBlockReward(44 * chain::General::REWARD_PERIOD + 1), 2547);


	EXPECT_EQ(chain::GetBlockReward(45 * chain::General::REWARD_PERIOD - 1), 2547);
	EXPECT_EQ(chain::GetBlockReward(45 * chain::General::REWARD_PERIOD), 1911);
	EXPECT_EQ(chain::GetBlockReward(45 * chain::General::REWARD_PERIOD + 1), 1911);


	EXPECT_EQ(chain::GetBlockReward(46 * chain::General::REWARD_PERIOD - 1), 1911);
	EXPECT_EQ(chain::GetBlockReward(46 * chain::General::REWARD_PERIOD), 1434);
	EXPECT_EQ(chain::GetBlockReward(46 * chain::General::REWARD_PERIOD + 1), 1434);


	EXPECT_EQ(chain::GetBlockReward(47 * chain::General::REWARD_PERIOD - 1), 1434);
	EXPECT_EQ(chain::GetBlockReward(47 * chain::General::REWARD_PERIOD), 1076);
	EXPECT_EQ(chain::GetBlockReward(47 * chain::General::REWARD_PERIOD + 1), 1076);


	EXPECT_EQ(chain::GetBlockReward(48 * chain::General::REWARD_PERIOD - 1), 1076);
	EXPECT_EQ(chain::GetBlockReward(48 * chain::General::REWARD_PERIOD), 807);
	EXPECT_EQ(chain::GetBlockReward(48 * chain::General::REWARD_PERIOD + 1), 807);


	EXPECT_EQ(chain::GetBlockReward(49 * chain::General::REWARD_PERIOD - 1), 807);
	EXPECT_EQ(chain::GetBlockReward(49 * chain::General::REWARD_PERIOD), 606);
	EXPECT_EQ(chain::GetBlockReward(49 * chain::General::REWARD_PERIOD + 1), 606);


	EXPECT_EQ(chain::GetBlockReward(50 * chain::General::REWARD_PERIOD - 1), 606);
	EXPECT_EQ(chain::GetBlockReward(50 * chain::General::REWARD_PERIOD), 455);
	EXPECT_EQ(chain::GetBlockReward(50 * chain::General::REWARD_PERIOD + 1), 455);


	EXPECT_EQ(chain::GetBlockReward(51 * chain::General::REWARD_PERIOD - 1), 455);
	EXPECT_EQ(chain::GetBlockReward(51 * chain::General::REWARD_PERIOD), 342);
	EXPECT_EQ(chain::GetBlockReward(51 * chain::General::REWARD_PERIOD + 1), 342);


	EXPECT_EQ(chain::GetBlockReward(52 * chain::General::REWARD_PERIOD - 1), 342);
	EXPECT_EQ(chain::GetBlockReward(52 * chain::General::REWARD_PERIOD), 257);
	EXPECT_EQ(chain::GetBlockReward(52 * chain::General::REWARD_PERIOD + 1), 257);


	EXPECT_EQ(chain::GetBlockReward(53 * chain::General::REWARD_PERIOD - 1), 257);
	EXPECT_EQ(chain::GetBlockReward(53 * chain::General::REWARD_PERIOD), 193);
	EXPECT_EQ(chain::GetBlockReward(53 * chain::General::REWARD_PERIOD + 1), 193);


	EXPECT_EQ(chain::GetBlockReward(54 * chain::General::REWARD_PERIOD - 1), 193);
	EXPECT_EQ(chain::GetBlockReward(54 * chain::General::REWARD_PERIOD), 145);
	EXPECT_EQ(chain::GetBlockReward(54 * chain::General::REWARD_PERIOD + 1), 145);


	EXPECT_EQ(chain::GetBlockReward(55 * chain::General::REWARD_PERIOD - 1), 145);
	EXPECT_EQ(chain::GetBlockReward(55 * chain::General::REWARD_PERIOD), 109);
	EXPECT_EQ(chain::GetBlockReward(55 * chain::General::REWARD_PERIOD + 1), 109);


	EXPECT_EQ(chain::GetBlockReward(56 * chain::General::REWARD_PERIOD - 1), 109);
	EXPECT_EQ(chain::GetBlockReward(56 * chain::General::REWARD_PERIOD), 82);
	EXPECT_EQ(chain::GetBlockReward(56 * chain::General::REWARD_PERIOD + 1), 82);


	EXPECT_EQ(chain::GetBlockReward(57 * chain::General::REWARD_PERIOD - 1), 82);
	EXPECT_EQ(chain::GetBlockReward(57 * chain::General::REWARD_PERIOD), 62);
	EXPECT_EQ(chain::GetBlockReward(57 * chain::General::REWARD_PERIOD + 1), 62);


	EXPECT_EQ(chain::GetBlockReward(58 * chain::General::REWARD_PERIOD - 1), 62);
	EXPECT_EQ(chain::GetBlockReward(58 * chain::General::REWARD_PERIOD), 47);
	EXPECT_EQ(chain::GetBlockReward(58 * chain::General::REWARD_PERIOD + 1), 47);


	EXPECT_EQ(chain::GetBlockReward(59 * chain::General::REWARD_PERIOD - 1), 47);
	EXPECT_EQ(chain::GetBlockReward(59 * chain::General::REWARD_PERIOD), 36);
	EXPECT_EQ(chain::GetBlockReward(59 * chain::General::REWARD_PERIOD + 1), 36);


	EXPECT_EQ(chain::GetBlockReward(60 * chain::General::REWARD_PERIOD - 1), 36);
	EXPECT_EQ(chain::GetBlockReward(60 * chain::General::REWARD_PERIOD), 27);
	EXPECT_EQ(chain::GetBlockReward(60 * chain::General::REWARD_PERIOD + 1), 27);


	EXPECT_EQ(chain::GetBlockReward(61 * chain::General::REWARD_PERIOD - 1), 27);
	EXPECT_EQ(chain::GetBlockReward(61 * chain::General::REWARD_PERIOD), 21);
	EXPECT_EQ(chain::GetBlockReward(61 * chain::General::REWARD_PERIOD + 1), 21);


	EXPECT_EQ(chain::GetBlockReward(62 * chain::General::REWARD_PERIOD - 1), 21);
	EXPECT_EQ(chain::GetBlockReward(62 * chain::General::REWARD_PERIOD), 16);
	EXPECT_EQ(chain::GetBlockReward(62 * chain::General::REWARD_PERIOD + 1), 16);


	EXPECT_EQ(chain::GetBlockReward(63 * chain::General::REWARD_PERIOD - 1), 16);
	EXPECT_EQ(chain::GetBlockReward(63 * chain::General::REWARD_PERIOD), 12);
	EXPECT_EQ(chain::GetBlockReward(63 * chain::General::REWARD_PERIOD + 1), 12);


	EXPECT_EQ(chain::GetBlockReward(64 * chain::General::REWARD_PERIOD - 1), 12);
	EXPECT_EQ(chain::GetBlockReward(64 * chain::General::REWARD_PERIOD), 9);
	EXPECT_EQ(chain::GetBlockReward(64 * chain::General::REWARD_PERIOD + 1), 9);


	EXPECT_EQ(chain::GetBlockReward(65 * chain::General::REWARD_PERIOD - 1), 9);
	EXPECT_EQ(chain::GetBlockReward(65 * chain::General::REWARD_PERIOD), 7);
	EXPECT_EQ(chain::GetBlockReward(65 * chain::General::REWARD_PERIOD + 1), 7);


	EXPECT_EQ(chain::GetBlockReward(66 * chain::General::REWARD_PERIOD - 1), 7);
	EXPECT_EQ(chain::GetBlockReward(66 * chain::General::REWARD_PERIOD), 6);
	EXPECT_EQ(chain::GetBlockReward(66 * chain::General::REWARD_PERIOD + 1), 6);


	EXPECT_EQ(chain::GetBlockReward(67 * chain::General::REWARD_PERIOD - 1), 6);
	EXPECT_EQ(chain::GetBlockReward(67 * chain::General::REWARD_PERIOD), 5);
	EXPECT_EQ(chain::GetBlockReward(67 * chain::General::REWARD_PERIOD + 1), 5);

	EXPECT_EQ(chain::GetBlockReward(68 * chain::General::REWARD_PERIOD - 1), 5);
	EXPECT_EQ(chain::GetBlockReward(68 * chain::General::REWARD_PERIOD), 4);
	EXPECT_EQ(chain::GetBlockReward(68 * chain::General::REWARD_PERIOD + 1), 4);

	EXPECT_EQ(chain::GetBlockReward(69 * chain::General::REWARD_PERIOD - 1), 4);
	EXPECT_EQ(chain::GetBlockReward(69 * chain::General::REWARD_PERIOD), 3);
	EXPECT_EQ(chain::GetBlockReward(69 * chain::General::REWARD_PERIOD + 1), 3);

	EXPECT_EQ(chain::GetBlockReward(70 * chain::General::REWARD_PERIOD - 1), 3);
	EXPECT_EQ(chain::GetBlockReward(70 * chain::General::REWARD_PERIOD), 2);
	EXPECT_EQ(chain::GetBlockReward(70 * chain::General::REWARD_PERIOD + 1), 2);

	EXPECT_EQ(chain::GetBlockReward(71 * chain::General::REWARD_PERIOD - 1), 2);
	EXPECT_EQ(chain::GetBlockReward(71 * chain::General::REWARD_PERIOD), 1);
	EXPECT_EQ(chain::GetBlockReward(71 * chain::General::REWARD_PERIOD + 1), 1);

	EXPECT_EQ(chain::GetBlockReward(72 * chain::General::REWARD_PERIOD - 1), 1);
	EXPECT_EQ(chain::GetBlockReward(72 * chain::General::REWARD_PERIOD), 0);
	EXPECT_EQ(chain::GetBlockReward(72 * chain::General::REWARD_PERIOD + 1), 0);

	EXPECT_EQ(chain::GetBlockReward(73 * chain::General::REWARD_PERIOD - 1), 0);
	EXPECT_EQ(chain::GetBlockReward(73 * chain::General::REWARD_PERIOD), 0);
	EXPECT_EQ(chain::GetBlockReward(73 * chain::General::REWARD_PERIOD + 1), 0);

	EXPECT_EQ(chain::GetBlockReward(74 * chain::General::REWARD_PERIOD - 1), 0);
	EXPECT_EQ(chain::GetBlockReward(74 * chain::General::REWARD_PERIOD), 0);
	EXPECT_EQ(chain::GetBlockReward(74 * chain::General::REWARD_PERIOD + 1), 0);

	EXPECT_EQ(chain::GetBlockReward(1000 * chain::General::REWARD_PERIOD - 1), 0);
	EXPECT_EQ(chain::GetBlockReward(1000 * chain::General::REWARD_PERIOD), 0);
	EXPECT_EQ(chain::GetBlockReward(1000 * chain::General::REWARD_PERIOD + 1), 0);

}
