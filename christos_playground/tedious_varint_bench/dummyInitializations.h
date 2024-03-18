#include"dummy.pb.h"
#include<random>

void initializeSmallDummy(smallVarintDummy* dummy, int mode)
{
	assert(mode > 0 && mode < 7);
	// create a random varint array, where each cell has a random integer value
	// 6 modes:
	// 1) everything 1 byte
	// 2) everything 2 bytes
	// 3) everything 3 bytes
	// 4) everything 4 bytes
	// 5) completely random
	// 6) uniformly distributed (1 byte, 2 bytes, 3 bytes, 4 bytes, 1 byte, 2 bytes, 3 bytes, 4 bytes, and so on)

	uint32_t randarr[50];
	// Create a random number generator engine
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator with the random device

    // Define a distribution (in this case, uniform distribution)
	std::uniform_int_distribution<> distrib1(0, 255);
	std::uniform_int_distribution<> distrib2(256, 2000);
	std::uniform_int_distribution<> distrib3(1<<16, (1<<24)-1);
	std::uniform_int_distribution<> distrib4(1<<24, (1<<26));
	std::uniform_int_distribution<> distrib6(0, 1<<26);

	for (int i = 0; i < 50; i++) {
		if (mode == 1)
			randarr[i] = distrib1(gen);
		if (mode == 2)
			randarr[i] = distrib2(gen);
		if (mode == 3)
			randarr[i] = distrib3(gen);
		if (mode == 4)
			randarr[i] = distrib4(gen);
		if (mode == 5)
			randarr[i] = distrib6(gen);
		if (mode == 6)
			if(i % 4 == 0) randarr[i] = distrib1(gen);
			else if(i % 4 == 1) randarr[i] = distrib2(gen);
			else if(i % 4 == 2) randarr[i] = distrib3(gen);
			else if(i % 4 == 3) randarr[i] = distrib4(gen);
		//std::cout << randarr[i] << std::endl;
	}

	dummy->set_id1(randarr[0]);
	dummy->set_id2(randarr[1]);
	dummy->set_id3(randarr[2]);
	dummy->set_id4(randarr[3]);
	dummy->set_id5(randarr[4]);
	dummy->set_id6(randarr[5]);
	dummy->set_id7(randarr[6]);
	dummy->set_id8(randarr[7]);
	dummy->set_id9(randarr[8]);
	dummy->set_id10(randarr[9]);
	dummy->set_id11(randarr[10]);
	dummy->set_id12(randarr[11]);
	dummy->set_id13(randarr[12]);
	dummy->set_id14(randarr[13]);
	dummy->set_id15(randarr[14]);
	dummy->set_id16(randarr[15]);
	dummy->set_id17(randarr[16]);
	dummy->set_id18(randarr[17]);
	dummy->set_id19(randarr[18]);
	dummy->set_id20(randarr[19]);
	dummy->set_id21(randarr[20]);
	dummy->set_id22(randarr[21]);
	dummy->set_id23(randarr[22]);
	dummy->set_id24(randarr[23]);
	dummy->set_id25(randarr[24]);
	dummy->set_id26(randarr[25]);
	dummy->set_id27(randarr[26]);
	dummy->set_id28(randarr[27]);
	dummy->set_id29(randarr[28]);
	dummy->set_id30(randarr[29]);
	dummy->set_id31(randarr[30]);
	dummy->set_id32(randarr[31]);
	dummy->set_id33(randarr[32]);
	dummy->set_id34(randarr[33]);
	dummy->set_id35(randarr[34]);
	dummy->set_id36(randarr[35]);
	dummy->set_id37(randarr[36]);
	dummy->set_id38(randarr[37]);
	dummy->set_id39(randarr[38]);
	dummy->set_id40(randarr[39]);
	dummy->set_id41(randarr[40]);
	dummy->set_id42(randarr[41]);
	dummy->set_id43(randarr[42]);
	dummy->set_id44(randarr[43]);
	dummy->set_id45(randarr[44]);
	dummy->set_id46(randarr[45]);
	dummy->set_id47(randarr[46]);
	dummy->set_id48(randarr[47]);
	dummy->set_id49(randarr[48]);
	dummy->set_id50(randarr[49]);
}

void initializeBiggerDummy(biggerVarintDummy* dummy, int mode)
{
	assert(mode > 0 && mode < 7);
	// create a random varint array, where each cell has a random integer value
	// 6 modes:
	// 1) everything 1 byte
	// 2) everything 2 bytes
	// 3) everything 3 bytes
	// 4) everything 4 bytes
	// 5) completely random
	// 6) uniformly distributed (1 byte, 2 bytes, 3 bytes, 4 bytes, 1 byte, 2 bytes, 3 bytes, 4 bytes, and so on)

	uint32_t randarr[100];
	// Create a random number generator engine
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator with the random device

    // Define a distribution (in this case, uniform distribution)
	std::uniform_int_distribution<> distrib1(0, 255);
	std::uniform_int_distribution<> distrib2(256, 2000);
	std::uniform_int_distribution<> distrib3(1<<16, (1<<24)-1);
	std::uniform_int_distribution<> distrib4(1<<24, (1<<26));
	std::uniform_int_distribution<> distrib6(0, 1<<26);

	for (int i = 0; i < 100; i++) {
		if (mode == 1)
			randarr[i] = distrib1(gen);
		if (mode == 2)
			randarr[i] = distrib2(gen);
		if (mode == 3)
			randarr[i] = distrib3(gen);
		if (mode == 4)
			randarr[i] = distrib4(gen);
		if (mode == 5)
			randarr[i] = distrib6(gen);
		if (mode == 6)
			if(i % 4 == 0) randarr[i] = distrib1(gen);
			else if(i % 4 == 1) randarr[i] = distrib2(gen);
			else if(i % 4 == 2) randarr[i] = distrib3(gen);
			else if(i % 4 == 3) randarr[i] = distrib4(gen);
		//std::cout << randarr[i] << std::endl;
	}

	dummy->set_id1(randarr[0]);
	dummy->set_id2(randarr[1]);
	dummy->set_id3(randarr[2]);
	dummy->set_id4(randarr[3]);
	dummy->set_id5(randarr[4]);
	dummy->set_id6(randarr[5]);
	dummy->set_id7(randarr[6]);
	dummy->set_id8(randarr[7]);
	dummy->set_id9(randarr[8]);
	dummy->set_id10(randarr[9]);
	dummy->set_id11(randarr[10]);
	dummy->set_id12(randarr[11]);
	dummy->set_id13(randarr[12]);
	dummy->set_id14(randarr[13]);
	dummy->set_id15(randarr[14]);
	dummy->set_id16(randarr[15]);
	dummy->set_id17(randarr[16]);
	dummy->set_id18(randarr[17]);
	dummy->set_id19(randarr[18]);
	dummy->set_id20(randarr[19]);
	dummy->set_id21(randarr[20]);
	dummy->set_id22(randarr[21]);
	dummy->set_id23(randarr[22]);
	dummy->set_id24(randarr[23]);
	dummy->set_id25(randarr[24]);
	dummy->set_id26(randarr[25]);
	dummy->set_id27(randarr[26]);
	dummy->set_id28(randarr[27]);
	dummy->set_id29(randarr[28]);
	dummy->set_id30(randarr[29]);
	dummy->set_id31(randarr[30]);
	dummy->set_id32(randarr[31]);
	dummy->set_id33(randarr[32]);
	dummy->set_id34(randarr[33]);
	dummy->set_id35(randarr[34]);
	dummy->set_id36(randarr[35]);
	dummy->set_id37(randarr[36]);
	dummy->set_id38(randarr[37]);
	dummy->set_id39(randarr[38]);
	dummy->set_id40(randarr[39]);
	dummy->set_id41(randarr[40]);
	dummy->set_id42(randarr[41]);
	dummy->set_id43(randarr[42]);
	dummy->set_id44(randarr[43]);
	dummy->set_id45(randarr[44]);
	dummy->set_id46(randarr[45]);
	dummy->set_id47(randarr[46]);
	dummy->set_id48(randarr[47]);
	dummy->set_id49(randarr[48]);
	dummy->set_id50(randarr[49]);
	dummy->set_id51(randarr[50]);
	dummy->set_id52(randarr[51]);
	dummy->set_id53(randarr[52]);
	dummy->set_id54(randarr[53]);
	dummy->set_id55(randarr[54]);
	dummy->set_id56(randarr[55]);
	dummy->set_id57(randarr[56]);
	dummy->set_id58(randarr[57]);
	dummy->set_id59(randarr[58]);
	dummy->set_id60(randarr[59]);
	dummy->set_id61(randarr[60]);
	dummy->set_id62(randarr[61]);
	dummy->set_id63(randarr[62]);
	dummy->set_id64(randarr[63]);
	dummy->set_id65(randarr[64]);
	dummy->set_id66(randarr[65]);
	dummy->set_id67(randarr[66]);
	dummy->set_id68(randarr[67]);
	dummy->set_id69(randarr[68]);
	dummy->set_id70(randarr[69]);
	dummy->set_id71(randarr[70]);
	dummy->set_id72(randarr[71]);
	dummy->set_id73(randarr[72]);
	dummy->set_id74(randarr[73]);
	dummy->set_id75(randarr[74]);
	dummy->set_id76(randarr[75]);
	dummy->set_id77(randarr[76]);
	dummy->set_id78(randarr[77]);
	dummy->set_id79(randarr[78]);
	dummy->set_id80(randarr[79]);
	dummy->set_id81(randarr[80]);
	dummy->set_id82(randarr[81]);
	dummy->set_id83(randarr[82]);
	dummy->set_id84(randarr[83]);
	dummy->set_id85(randarr[84]);
	dummy->set_id86(randarr[85]);
	dummy->set_id87(randarr[86]);
	dummy->set_id88(randarr[87]);
	dummy->set_id89(randarr[88]);
	dummy->set_id90(randarr[89]);
	dummy->set_id91(randarr[90]);
	dummy->set_id92(randarr[91]);
	dummy->set_id93(randarr[92]);
	dummy->set_id94(randarr[93]);
	dummy->set_id95(randarr[94]);
	dummy->set_id96(randarr[95]);
	dummy->set_id97(randarr[96]);
	dummy->set_id98(randarr[97]);
	dummy->set_id99(randarr[98]);
	dummy->set_id100(randarr[99]);
}

void initializeEvenBiggerDummy(evenBiggerVarintDummy* dummy, int mode)
{
	assert(mode > 0 && mode < 7);
	// create a random varint array, where each cell has a random integer value
	// 6 modes:
	// 1) everything 1 byte
	// 2) everything 2 bytes
	// 3) everything 3 bytes
	// 4) everything 4 bytes
	// 5) completely random
	// 6) uniformly distributed (1 byte, 2 bytes, 3 bytes, 4 bytes, 1 byte, 2 bytes, 3 bytes, 4 bytes, and so on)

	uint32_t randarr[200];
	// Create a random number generator engine
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator with the random device

    // Define a distribution (in this case, uniform distribution)
	std::uniform_int_distribution<> distrib1(0, 255);
	std::uniform_int_distribution<> distrib2(256, 2000);
	std::uniform_int_distribution<> distrib3(1<<16, (1<<24)-1);
	std::uniform_int_distribution<> distrib4(1<<24, (1<<26));
	std::uniform_int_distribution<> distrib6(0, 1<<26);

	for (int i = 0; i < 200; i++) {
		if (mode == 1)
			randarr[i] = distrib1(gen);
		if (mode == 2)
			randarr[i] = distrib2(gen);
		if (mode == 3)
			randarr[i] = distrib3(gen);
		if (mode == 4)
			randarr[i] = distrib4(gen);
		if (mode == 5)
			randarr[i] = distrib6(gen);
		if (mode == 6)
			if(i % 4 == 0) randarr[i] = distrib1(gen);
			else if(i % 4 == 1) randarr[i] = distrib2(gen);
			else if(i % 4 == 2) randarr[i] = distrib3(gen);
			else if(i % 4 == 3) randarr[i] = distrib4(gen);
		//std::cout << randarr[i] << std::endl;
	}

	dummy->set_id1(randarr[0]);
	dummy->set_id2(randarr[1]);
	dummy->set_id3(randarr[2]);
	dummy->set_id4(randarr[3]);
	dummy->set_id5(randarr[4]);
	dummy->set_id6(randarr[5]);
	dummy->set_id7(randarr[6]);
	dummy->set_id8(randarr[7]);
	dummy->set_id9(randarr[8]);
	dummy->set_id10(randarr[9]);
	dummy->set_id11(randarr[10]);
	dummy->set_id12(randarr[11]);
	dummy->set_id13(randarr[12]);
	dummy->set_id14(randarr[13]);
	dummy->set_id15(randarr[14]);
	dummy->set_id16(randarr[15]);
	dummy->set_id17(randarr[16]);
	dummy->set_id18(randarr[17]);
	dummy->set_id19(randarr[18]);
	dummy->set_id20(randarr[19]);
	dummy->set_id21(randarr[20]);
	dummy->set_id22(randarr[21]);
	dummy->set_id23(randarr[22]);
	dummy->set_id24(randarr[23]);
	dummy->set_id25(randarr[24]);
	dummy->set_id26(randarr[25]);
	dummy->set_id27(randarr[26]);
	dummy->set_id28(randarr[27]);
	dummy->set_id29(randarr[28]);
	dummy->set_id30(randarr[29]);
	dummy->set_id31(randarr[30]);
	dummy->set_id32(randarr[31]);
	dummy->set_id33(randarr[32]);
	dummy->set_id34(randarr[33]);
	dummy->set_id35(randarr[34]);
	dummy->set_id36(randarr[35]);
	dummy->set_id37(randarr[36]);
	dummy->set_id38(randarr[37]);
	dummy->set_id39(randarr[38]);
	dummy->set_id40(randarr[39]);
	dummy->set_id41(randarr[40]);
	dummy->set_id42(randarr[41]);
	dummy->set_id43(randarr[42]);
	dummy->set_id44(randarr[43]);
	dummy->set_id45(randarr[44]);
	dummy->set_id46(randarr[45]);
	dummy->set_id47(randarr[46]);
	dummy->set_id48(randarr[47]);
	dummy->set_id49(randarr[48]);
	dummy->set_id50(randarr[49]);
	dummy->set_id51(randarr[50]);
	dummy->set_id52(randarr[51]);
	dummy->set_id53(randarr[52]);
	dummy->set_id54(randarr[53]);
	dummy->set_id55(randarr[54]);
	dummy->set_id56(randarr[55]);
	dummy->set_id57(randarr[56]);
	dummy->set_id58(randarr[57]);
	dummy->set_id59(randarr[58]);
	dummy->set_id60(randarr[59]);
	dummy->set_id61(randarr[60]);
	dummy->set_id62(randarr[61]);
	dummy->set_id63(randarr[62]);
	dummy->set_id64(randarr[63]);
	dummy->set_id65(randarr[64]);
	dummy->set_id66(randarr[65]);
	dummy->set_id67(randarr[66]);
	dummy->set_id68(randarr[67]);
	dummy->set_id69(randarr[68]);
	dummy->set_id70(randarr[69]);
	dummy->set_id71(randarr[70]);
	dummy->set_id72(randarr[71]);
	dummy->set_id73(randarr[72]);
	dummy->set_id74(randarr[73]);
	dummy->set_id75(randarr[74]);
	dummy->set_id76(randarr[75]);
	dummy->set_id77(randarr[76]);
	dummy->set_id78(randarr[77]);
	dummy->set_id79(randarr[78]);
	dummy->set_id80(randarr[79]);
	dummy->set_id81(randarr[80]);
	dummy->set_id82(randarr[81]);
	dummy->set_id83(randarr[82]);
	dummy->set_id84(randarr[83]);
	dummy->set_id85(randarr[84]);
	dummy->set_id86(randarr[85]);
	dummy->set_id87(randarr[86]);
	dummy->set_id88(randarr[87]);
	dummy->set_id89(randarr[88]);
	dummy->set_id90(randarr[89]);
	dummy->set_id91(randarr[90]);
	dummy->set_id92(randarr[91]);
	dummy->set_id93(randarr[92]);
	dummy->set_id94(randarr[93]);
	dummy->set_id95(randarr[94]);
	dummy->set_id96(randarr[95]);
	dummy->set_id97(randarr[96]);
	dummy->set_id98(randarr[97]);
	dummy->set_id99(randarr[98]);
	dummy->set_id100(randarr[99]);
	dummy->set_id101(randarr[100]);
	dummy->set_id102(randarr[101]);
	dummy->set_id103(randarr[102]);
	dummy->set_id104(randarr[103]);
	dummy->set_id105(randarr[104]);
	dummy->set_id106(randarr[105]);
	dummy->set_id107(randarr[106]);
	dummy->set_id108(randarr[107]);
	dummy->set_id109(randarr[108]);
	dummy->set_id110(randarr[109]);
	dummy->set_id111(randarr[110]);
	dummy->set_id112(randarr[111]);
	dummy->set_id113(randarr[112]);
	dummy->set_id114(randarr[113]);
	dummy->set_id115(randarr[114]);
	dummy->set_id116(randarr[115]);
	dummy->set_id117(randarr[116]);
	dummy->set_id118(randarr[117]);
	dummy->set_id119(randarr[118]);
	dummy->set_id120(randarr[119]);
	dummy->set_id121(randarr[120]);
	dummy->set_id122(randarr[121]);
	dummy->set_id123(randarr[122]);
	dummy->set_id124(randarr[123]);
	dummy->set_id125(randarr[124]);
	dummy->set_id126(randarr[125]);
	dummy->set_id127(randarr[126]);
	dummy->set_id128(randarr[127]);
	dummy->set_id129(randarr[128]);
	dummy->set_id130(randarr[129]);
	dummy->set_id131(randarr[130]);
	dummy->set_id132(randarr[131]);
	dummy->set_id133(randarr[132]);
	dummy->set_id134(randarr[133]);
	dummy->set_id135(randarr[134]);
	dummy->set_id136(randarr[135]);
	dummy->set_id137(randarr[136]);
	dummy->set_id138(randarr[137]);
	dummy->set_id139(randarr[138]);
	dummy->set_id140(randarr[139]);
	dummy->set_id141(randarr[140]);
	dummy->set_id142(randarr[141]);
	dummy->set_id143(randarr[142]);
	dummy->set_id144(randarr[143]);
	dummy->set_id145(randarr[144]);
	dummy->set_id146(randarr[145]);
	dummy->set_id147(randarr[146]);
	dummy->set_id148(randarr[147]);
	dummy->set_id149(randarr[148]);
	dummy->set_id150(randarr[149]);
	dummy->set_id151(randarr[150]);
	dummy->set_id152(randarr[151]);
	dummy->set_id153(randarr[152]);
	dummy->set_id154(randarr[153]);
	dummy->set_id155(randarr[154]);
	dummy->set_id156(randarr[155]);
	dummy->set_id157(randarr[156]);
	dummy->set_id158(randarr[157]);
	dummy->set_id159(randarr[158]);
	dummy->set_id160(randarr[159]);
	dummy->set_id161(randarr[160]);
	dummy->set_id162(randarr[161]);
	dummy->set_id163(randarr[162]);
	dummy->set_id164(randarr[163]);
	dummy->set_id165(randarr[164]);
	dummy->set_id166(randarr[165]);
	dummy->set_id167(randarr[166]);
	dummy->set_id168(randarr[167]);
	dummy->set_id169(randarr[168]);
	dummy->set_id170(randarr[169]);
	dummy->set_id171(randarr[170]);
	dummy->set_id172(randarr[171]);
	dummy->set_id173(randarr[172]);
	dummy->set_id174(randarr[173]);
	dummy->set_id175(randarr[174]);
	dummy->set_id176(randarr[175]);
	dummy->set_id177(randarr[176]);
	dummy->set_id178(randarr[177]);
	dummy->set_id179(randarr[178]);
	dummy->set_id180(randarr[179]);
	dummy->set_id181(randarr[180]);
	dummy->set_id182(randarr[181]);
	dummy->set_id183(randarr[182]);
	dummy->set_id184(randarr[183]);
	dummy->set_id185(randarr[184]);
	dummy->set_id186(randarr[185]);
	dummy->set_id187(randarr[186]);
	dummy->set_id188(randarr[187]);
	dummy->set_id189(randarr[188]);
	dummy->set_id190(randarr[189]);
	dummy->set_id191(randarr[190]);
	dummy->set_id192(randarr[191]);
	dummy->set_id193(randarr[192]);
	dummy->set_id194(randarr[193]);
	dummy->set_id195(randarr[194]);
	dummy->set_id196(randarr[195]);
	dummy->set_id197(randarr[196]);
	dummy->set_id198(randarr[197]);
	dummy->set_id199(randarr[198]);
	dummy->set_id200(randarr[199]);
}
