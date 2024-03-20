#include <google/protobuf/util/message_differencer.h>

#include <fstream>
#include <iostream>
#include <string>

#include "person.pb.h"

static constexpr size_t kNofIterations = 10000;
static constexpr size_t kNofWarmUpIterations = 100;

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  std::vector<M> messages;
  std::vector<std::string> outs;
  for (size_t i = 0; i < kNofIterations; ++i) {
    M m;
    // <------------ SETTERS ------>
(&m)->set_f1(12632488 + (i * 1) % 8);
(&m)->set_f2(254 + (i * 1) % 8);
(&m)->set_f3(2992253 + (i * 1) % 8);
(&m)->set_f4(1347486 + (i * 1) % 8);
(&m)->set_f5(47 + (i * 1) % 8);
(&m)->set_f6(2935772314 + (i * 1) % 8);
(&m)->set_f7(57 + (i * 1) % 8);
(&m)->set_f8(44846 + (i * 1) % 8);
(&m)->set_f9(50 + (i * 1) % 8);
(&m)->set_f10(14736441 + (i * 1) % 8);
(&m)->set_f11(158 + (i * 1) % 8);
(&m)->set_f12(59 + (i * 1) % 8);
(&m)->set_f13(17622 + (i * 1) % 8);
(&m)->set_f14(252 + (i * 1) % 8);
(&m)->set_f15(65125 + (i * 1) % 8);
(&m)->set_f16(10642989 + (i * 1) % 8);
(&m)->set_f17(3864533309 + (i * 1) % 8);
(&m)->set_f18(1712849150 + (i * 1) % 8);
(&m)->set_f19(2453422401 + (i * 1) % 8);
(&m)->set_f20(27128 + (i * 1) % 8);
(&m)->set_f21(3830797 + (i * 1) % 8);
(&m)->set_f22(3678161597 + (i * 1) % 8);
(&m)->set_f23(2401121421 + (i * 1) % 8);
(&m)->set_f24(141 + (i * 1) % 8);
(&m)->set_f25(4248359594 + (i * 1) % 8);
(&m)->set_f26(142 + (i * 1) % 8);
(&m)->set_f27(79 + (i * 1) % 8);
(&m)->set_f28(134 + (i * 1) % 8);
(&m)->set_f29(1002724344 + (i * 1) % 8);
(&m)->set_f30(3309135616 + (i * 1) % 8);
(&m)->set_f31(39497 + (i * 1) % 8);
(&m)->set_f32(1164040 + (i * 1) % 8);
(&m)->set_f33(157 + (i * 1) % 8);
(&m)->set_f34(30384 + (i * 1) % 8);
(&m)->set_f35(10952 + (i * 1) % 8);
(&m)->set_f36(38 + (i * 1) % 8);
(&m)->set_f37(196 + (i * 1) % 8);
(&m)->set_f38(172 + (i * 1) % 8);
(&m)->set_f39(254 + (i * 1) % 8);
(&m)->set_f40(59396 + (i * 1) % 8);
(&m)->set_f41(6637 + (i * 1) % 8);
(&m)->set_f42(7488 + (i * 1) % 8);
(&m)->set_f43(8170059 + (i * 1) % 8);
(&m)->set_f44(138 + (i * 1) % 8);
(&m)->set_f45(723459012 + (i * 1) % 8);
(&m)->set_f46(31 + (i * 1) % 8);
(&m)->set_f47(11958505 + (i * 1) % 8);
(&m)->set_f48(40538 + (i * 1) % 8);
(&m)->set_f49(2771009076 + (i * 1) % 8);
(&m)->set_f50(57008 + (i * 1) % 8);
(&m)->set_f51(120 + (i * 1) % 8);
(&m)->set_f52(15298 + (i * 1) % 8);
(&m)->set_f53(164 + (i * 1) % 8);
(&m)->set_f54(56859 + (i * 1) % 8);
(&m)->set_f55(1114432388 + (i * 1) % 8);
(&m)->set_f56(1393926216 + (i * 1) % 8);
(&m)->set_f57(1294195565 + (i * 1) % 8);
(&m)->set_f58(125 + (i * 1) % 8);
(&m)->set_f59(2487841998 + (i * 1) % 8);
(&m)->set_f60(2247444968 + (i * 1) % 8);
(&m)->set_f61(8607213 + (i * 1) % 8);
(&m)->set_f62(11392 + (i * 1) % 8);
(&m)->set_f63(3613474285 + (i * 1) % 8);
(&m)->set_f64(40165 + (i * 1) % 8);
(&m)->set_f65(11568448 + (i * 1) % 8);
(&m)->set_f66(127 + (i * 1) % 8);
(&m)->set_f67(246 + (i * 1) % 8);
(&m)->set_f68(11622 + (i * 1) % 8);
(&m)->set_f69(12210684 + (i * 1) % 8);
(&m)->set_f70(41084 + (i * 1) % 8);
(&m)->set_f71(913458309 + (i * 1) % 8);
(&m)->set_f72(27059 + (i * 1) % 8);
(&m)->set_f73(2197654792 + (i * 1) % 8);
(&m)->set_f74(3464581 + (i * 1) % 8);
(&m)->set_f75(125 + (i * 1) % 8);
(&m)->set_f76(5146715 + (i * 1) % 8);
(&m)->set_f77(64888 + (i * 1) % 8);
(&m)->set_f78(2854029755 + (i * 1) % 8);
(&m)->set_f79(2531920593 + (i * 1) % 8);
(&m)->set_f80(2368228829 + (i * 1) % 8);
(&m)->set_f81(223 + (i * 1) % 8);
(&m)->set_f82(2 + (i * 1) % 8);
(&m)->set_f83(252 + (i * 1) % 8);
(&m)->set_f84(11904 + (i * 1) % 8);
(&m)->set_f85(4256805366 + (i * 1) % 8);
(&m)->set_f86(7265737 + (i * 1) % 8);
(&m)->set_f87(179 + (i * 1) % 8);
(&m)->set_f88(11250622 + (i * 1) % 8);
(&m)->set_f89(4920335 + (i * 1) % 8);
(&m)->set_f90(12513623 + (i * 1) % 8);
(&m)->set_f91(20 + (i * 1) % 8);
(&m)->set_f92(2525845 + (i * 1) % 8);
(&m)->set_f93(2025320034 + (i * 1) % 8);
(&m)->set_f94(10203389 + (i * 1) % 8);
(&m)->set_f95(13348342 + (i * 1) % 8);
(&m)->set_f96(47744 + (i * 1) % 8);
(&m)->set_f97(5 + (i * 1) % 8);
(&m)->set_f98(4129524778 + (i * 1) % 8);
(&m)->set_f99(2747890338 + (i * 1) % 8);
(&m)->set_f100(4830 + (i * 1) % 8);
(&m)->set_f101(95 + (i * 1) % 8);
(&m)->set_f102(7222956 + (i * 1) % 8);
(&m)->set_f103(4059481383 + (i * 1) % 8);
(&m)->set_f104(1613810087 + (i * 1) % 8);
(&m)->set_f105(37387 + (i * 1) % 8);
(&m)->set_f106(138 + (i * 1) % 8);
(&m)->set_f107(1271568929 + (i * 1) % 8);
(&m)->set_f108(1448126204 + (i * 1) % 8);
(&m)->set_f109(16159665 + (i * 1) % 8);
(&m)->set_f110(62 + (i * 1) % 8);
(&m)->set_f111(64269 + (i * 1) % 8);
(&m)->set_f112(11403966 + (i * 1) % 8);
(&m)->set_f113(15858 + (i * 1) % 8);
(&m)->set_f114(84 + (i * 1) % 8);
(&m)->set_f115(1809006349 + (i * 1) % 8);
(&m)->set_f116(2944098383 + (i * 1) % 8);
(&m)->set_f117(177 + (i * 1) % 8);
(&m)->set_f118(22970 + (i * 1) % 8);
(&m)->set_f119(255 + (i * 1) % 8);
(&m)->set_f120(50245 + (i * 1) % 8);
(&m)->set_f121(2934479577 + (i * 1) % 8);
(&m)->set_f122(35093 + (i * 1) % 8);
(&m)->set_f123(3844131 + (i * 1) % 8);
(&m)->set_f124(11413293 + (i * 1) % 8);
(&m)->set_f125(197 + (i * 1) % 8);
(&m)->set_f126(668453945 + (i * 1) % 8);
(&m)->set_f127(250 + (i * 1) % 8);
(&m)->set_f128(219 + (i * 1) % 8);
(&m)->set_f129(13043376 + (i * 1) % 8);
(&m)->set_f130(12263 + (i * 1) % 8);
(&m)->set_f131(34306 + (i * 1) % 8);
(&m)->set_f132(13142064 + (i * 1) % 8);
(&m)->set_f133(636 + (i * 1) % 8);
(&m)->set_f134(7282389 + (i * 1) % 8);
(&m)->set_f135(3680608 + (i * 1) % 8);
(&m)->set_f136(916122 + (i * 1) % 8);
(&m)->set_f137(2567786112 + (i * 1) % 8);
(&m)->set_f138(2176370599 + (i * 1) % 8);
(&m)->set_f139(1942293216 + (i * 1) % 8);
(&m)->set_f140(3777251749 + (i * 1) % 8);
(&m)->set_f141(13431954 + (i * 1) % 8);
(&m)->set_f142(292227315 + (i * 1) % 8);
(&m)->set_f143(1540843314 + (i * 1) % 8);
(&m)->set_f144(12463926 + (i * 1) % 8);
(&m)->set_f145(2518387532 + (i * 1) % 8);
(&m)->set_f146(8977472 + (i * 1) % 8);
(&m)->set_f147(1096808724 + (i * 1) % 8);
(&m)->set_f148(7487512 + (i * 1) % 8);
(&m)->set_f149(59 + (i * 1) % 8);
(&m)->set_f150(1787701860 + (i * 1) % 8);
(&m)->set_f151(8859872 + (i * 1) % 8);
(&m)->set_f152(5431075 + (i * 1) % 8);
(&m)->set_f153(666598831 + (i * 1) % 8);
(&m)->set_f154(59357 + (i * 1) % 8);
(&m)->set_f155(1064700287 + (i * 1) % 8);
(&m)->set_f156(35837 + (i * 1) % 8);
(&m)->set_f157(2392150502 + (i * 1) % 8);
(&m)->set_f158(10267982 + (i * 1) % 8);
(&m)->set_f159(1787551356 + (i * 1) % 8);
(&m)->set_f160(223 + (i * 1) % 8);
(&m)->set_f161(14552 + (i * 1) % 8);
(&m)->set_f162(1403962688 + (i * 1) % 8);
(&m)->set_f163(374695705 + (i * 1) % 8);
(&m)->set_f164(3133072813 + (i * 1) % 8);
(&m)->set_f165(3242393241 + (i * 1) % 8);
(&m)->set_f166(13161466 + (i * 1) % 8);
(&m)->set_f167(22282 + (i * 1) % 8);
(&m)->set_f168(63729 + (i * 1) % 8);
(&m)->set_f169(139 + (i * 1) % 8);
(&m)->set_f170(1008844 + (i * 1) % 8);
(&m)->set_f171(8974 + (i * 1) % 8);
(&m)->set_f172(3406686596 + (i * 1) % 8);
(&m)->set_f173(191 + (i * 1) % 8);
(&m)->set_f174(3078350 + (i * 1) % 8);
(&m)->set_f175(12191771 + (i * 1) % 8);
(&m)->set_f176(251 + (i * 1) % 8);
(&m)->set_f177(30099 + (i * 1) % 8);
(&m)->set_f178(12907707 + (i * 1) % 8);
(&m)->set_f179(216 + (i * 1) % 8);
(&m)->set_f180(8138006 + (i * 1) % 8);
(&m)->set_f181(5316052 + (i * 1) % 8);
(&m)->set_f182(33942 + (i * 1) % 8);
(&m)->set_f183(7493251 + (i * 1) % 8);
(&m)->set_f184(2359316854 + (i * 1) % 8);
(&m)->set_f185(125 + (i * 1) % 8);
(&m)->set_f186(46 + (i * 1) % 8);
(&m)->set_f187(5786101 + (i * 1) % 8);
(&m)->set_f188(3197917940 + (i * 1) % 8);
(&m)->set_f189(8921972 + (i * 1) % 8);
(&m)->set_f190(36 + (i * 1) % 8);
(&m)->set_f191(849171268 + (i * 1) % 8);
(&m)->set_f192(141 + (i * 1) % 8);
(&m)->set_f193(174 + (i * 1) % 8);
(&m)->set_f194(148 + (i * 1) % 8);
(&m)->set_f195(13648807 + (i * 1) % 8);
(&m)->set_f196(881015182 + (i * 1) % 8);
(&m)->set_f197(4284195344 + (i * 1) % 8);
(&m)->set_f198(54742 + (i * 1) % 8);
(&m)->set_f199(3152941088 + (i * 1) % 8);
(&m)->set_f200(1342584197 + (i * 1) % 8);
(&m)->set_f201(2594393563 + (i * 1) % 8);
(&m)->set_f202(1711 + (i * 1) % 8);
(&m)->set_f203(3892765776 + (i * 1) % 8);
(&m)->set_f204(8931583 + (i * 1) % 8);
(&m)->set_f205(4128994230 + (i * 1) % 8);
(&m)->set_f206(189 + (i * 1) % 8);
(&m)->set_f207(5572544 + (i * 1) % 8);
(&m)->set_f208(32322 + (i * 1) % 8);
(&m)->set_f209(12069965 + (i * 1) % 8);
(&m)->set_f210(44374 + (i * 1) % 8);
(&m)->set_f211(49425 + (i * 1) % 8);
(&m)->set_f212(1695348044 + (i * 1) % 8);
(&m)->set_f213(1569432860 + (i * 1) % 8);
(&m)->set_f214(1968041768 + (i * 1) % 8);
(&m)->set_f215(5590723 + (i * 1) % 8);
(&m)->set_f216(3939743 + (i * 1) % 8);
(&m)->set_f217(187 + (i * 1) % 8);
(&m)->set_f218(200 + (i * 1) % 8);
(&m)->set_f219(1000547941 + (i * 1) % 8);
(&m)->set_f220(18595 + (i * 1) % 8);
(&m)->set_f221(7157235 + (i * 1) % 8);
(&m)->set_f222(6481629 + (i * 1) % 8);
(&m)->set_f223(57393 + (i * 1) % 8);
(&m)->set_f224(6422 + (i * 1) % 8);
(&m)->set_f225(175 + (i * 1) % 8);
(&m)->set_f226(260001078 + (i * 1) % 8);
(&m)->set_f227(11749 + (i * 1) % 8);
(&m)->set_f228(58837 + (i * 1) % 8);
(&m)->set_f229(4265 + (i * 1) % 8);
(&m)->set_f230(3421732863 + (i * 1) % 8);
(&m)->set_f231(57333 + (i * 1) % 8);
(&m)->set_f232(45976 + (i * 1) % 8);
(&m)->set_f233(20460 + (i * 1) % 8);
(&m)->set_f234(4110041972 + (i * 1) % 8);
(&m)->set_f235(1272656826 + (i * 1) % 8);
(&m)->set_f236(34347 + (i * 1) % 8);
(&m)->set_f237(9417568 + (i * 1) % 8);
(&m)->set_f238(6020 + (i * 1) % 8);
(&m)->set_f239(10155041 + (i * 1) % 8);
(&m)->set_f240(92 + (i * 1) % 8);
(&m)->set_f241(56268 + (i * 1) % 8);
(&m)->set_f242(3844950 + (i * 1) % 8);
(&m)->set_f243(4129260811 + (i * 1) % 8);
(&m)->set_f244(16636531 + (i * 1) % 8);
(&m)->set_f245(223766410 + (i * 1) % 8);
(&m)->set_f246(202 + (i * 1) % 8);
(&m)->set_f247(48070 + (i * 1) % 8);
(&m)->set_f248(57131 + (i * 1) % 8);
(&m)->set_f249(127 + (i * 1) % 8);
(&m)->set_f250(14658784 + (i * 1) % 8);
(&m)->set_f251(16923 + (i * 1) % 8);
(&m)->set_f252(11001424 + (i * 1) % 8);
(&m)->set_f253(45946 + (i * 1) % 8);
(&m)->set_f254(12237753 + (i * 1) % 8);
(&m)->set_f255(21 + (i * 1) % 8);
(&m)->set_f256(14 + (i * 1) % 8);
(&m)->set_f257(2963545 + (i * 1) % 8);
(&m)->set_f258(6888770 + (i * 1) % 8);
(&m)->set_f259(14219385 + (i * 1) % 8);
(&m)->set_f260(28215 + (i * 1) % 8);
(&m)->set_f261(150 + (i * 1) % 8);
(&m)->set_f262(150 + (i * 1) % 8);
(&m)->set_f263(31 + (i * 1) % 8);
(&m)->set_f264(34985 + (i * 1) % 8);
(&m)->set_f265(60657 + (i * 1) % 8);
(&m)->set_f266(36627 + (i * 1) % 8);
(&m)->set_f267(208 + (i * 1) % 8);
(&m)->set_f268(16877 + (i * 1) % 8);
(&m)->set_f269(144 + (i * 1) % 8);
(&m)->set_f270(4187767800 + (i * 1) % 8);
(&m)->set_f271(24215 + (i * 1) % 8);
(&m)->set_f272(12800881 + (i * 1) % 8);
(&m)->set_f273(2081587988 + (i * 1) % 8);
(&m)->set_f274(58075 + (i * 1) % 8);
(&m)->set_f275(41544 + (i * 1) % 8);
(&m)->set_f276(2012822 + (i * 1) % 8);
(&m)->set_f277(108 + (i * 1) % 8);
(&m)->set_f278(7360580 + (i * 1) % 8);
(&m)->set_f279(26131 + (i * 1) % 8);
(&m)->set_f280(1810940406 + (i * 1) % 8);
(&m)->set_f281(97 + (i * 1) % 8);
(&m)->set_f282(226 + (i * 1) % 8);
(&m)->set_f283(973309886 + (i * 1) % 8);
(&m)->set_f284(13 + (i * 1) % 8);
(&m)->set_f285(2220916 + (i * 1) % 8);
(&m)->set_f286(209 + (i * 1) % 8);
(&m)->set_f287(165 + (i * 1) % 8);
(&m)->set_f288(117 + (i * 1) % 8);
(&m)->set_f289(6765928 + (i * 1) % 8);
(&m)->set_f290(34 + (i * 1) % 8);
(&m)->set_f291(2013013 + (i * 1) % 8);
(&m)->set_f292(45053 + (i * 1) % 8);
(&m)->set_f293(1407296905 + (i * 1) % 8);
(&m)->set_f294(37843 + (i * 1) % 8);
(&m)->set_f295(13770639 + (i * 1) % 8);
(&m)->set_f296(4130216807 + (i * 1) % 8);
(&m)->set_f297(7583524 + (i * 1) % 8);
(&m)->set_f298(236 + (i * 1) % 8);
(&m)->set_f299(6521957 + (i * 1) % 8);
(&m)->set_f300(54843 + (i * 1) % 8);
(&m)->set_f301(11716 + (i * 1) % 8);
(&m)->set_f302(2918688023 + (i * 1) % 8);
(&m)->set_f303(4033016061 + (i * 1) % 8);
(&m)->set_f304(2071201398 + (i * 1) % 8);
(&m)->set_f305(245 + (i * 1) % 8);
(&m)->set_f306(809921 + (i * 1) % 8);
(&m)->set_f307(6124032 + (i * 1) % 8);
(&m)->set_f308(4750294 + (i * 1) % 8);
(&m)->set_f309(3639259414 + (i * 1) % 8);
(&m)->set_f310(136 + (i * 1) % 8);
(&m)->set_f311(49 + (i * 1) % 8);
(&m)->set_f312(181 + (i * 1) % 8);
(&m)->set_f313(2676507078 + (i * 1) % 8);
(&m)->set_f314(9934262 + (i * 1) % 8);
(&m)->set_f315(53754 + (i * 1) % 8);
(&m)->set_f316(52071 + (i * 1) % 8);
(&m)->set_f317(99 + (i * 1) % 8);
(&m)->set_f318(18285 + (i * 1) % 8);
(&m)->set_f319(59695 + (i * 1) % 8);
(&m)->set_f320(106 + (i * 1) % 8);
(&m)->set_f321(209 + (i * 1) % 8);
(&m)->set_f322(118 + (i * 1) % 8);
(&m)->set_f323(1762 + (i * 1) % 8);
(&m)->set_f324(4079721 + (i * 1) % 8);
(&m)->set_f325(3953273582 + (i * 1) % 8);
(&m)->set_f326(34746 + (i * 1) % 8);
(&m)->set_f327(202 + (i * 1) % 8);
(&m)->set_f328(1545263 + (i * 1) % 8);
(&m)->set_f329(1405609108 + (i * 1) % 8);
(&m)->set_f330(1108924908 + (i * 1) % 8);
(&m)->set_f331(5273056 + (i * 1) % 8);
(&m)->set_f332(1317280 + (i * 1) % 8);
(&m)->set_f333(1812991765 + (i * 1) % 8);
(&m)->set_f334(59722 + (i * 1) % 8);
(&m)->set_f335(554827708 + (i * 1) % 8);
(&m)->set_f336(199 + (i * 1) % 8);
(&m)->set_f337(53700 + (i * 1) % 8);
(&m)->set_f338(185 + (i * 1) % 8);
(&m)->set_f339(23784 + (i * 1) % 8);
(&m)->set_f340(18 + (i * 1) % 8);
(&m)->set_f341(63 + (i * 1) % 8);
(&m)->set_f342(3065698607 + (i * 1) % 8);
(&m)->set_f343(965466 + (i * 1) % 8);
(&m)->set_f344(46806 + (i * 1) % 8);
(&m)->set_f345(5357752 + (i * 1) % 8);
(&m)->set_f346(2375307577 + (i * 1) % 8);
(&m)->set_f347(63226 + (i * 1) % 8);
(&m)->set_f348(3691395376 + (i * 1) % 8);
(&m)->set_f349(64 + (i * 1) % 8);
(&m)->set_f350(3210734397 + (i * 1) % 8);
(&m)->set_f351(34055 + (i * 1) % 8);
(&m)->set_f352(40522 + (i * 1) % 8);
(&m)->set_f353(128 + (i * 1) % 8);
(&m)->set_f354(63750 + (i * 1) % 8);
(&m)->set_f355(10893 + (i * 1) % 8);
(&m)->set_f356(248 + (i * 1) % 8);
(&m)->set_f357(1740119610 + (i * 1) % 8);
(&m)->set_f358(38371 + (i * 1) % 8);
(&m)->set_f359(102 + (i * 1) % 8);
(&m)->set_f360(109 + (i * 1) % 8);
(&m)->set_f361(5912883 + (i * 1) % 8);
(&m)->set_f362(160156606 + (i * 1) % 8);
(&m)->set_f363(51406 + (i * 1) % 8);
(&m)->set_f364(207 + (i * 1) % 8);
(&m)->set_f365(12244300 + (i * 1) % 8);
(&m)->set_f366(17197 + (i * 1) % 8);
(&m)->set_f367(513016510 + (i * 1) % 8);
(&m)->set_f368(4253305401 + (i * 1) % 8);
(&m)->set_f369(27 + (i * 1) % 8);
(&m)->set_f370(15496716 + (i * 1) % 8);
(&m)->set_f371(2915805413 + (i * 1) % 8);
(&m)->set_f372(2959064784 + (i * 1) % 8);
(&m)->set_f373(48974 + (i * 1) % 8);
(&m)->set_f374(1201641826 + (i * 1) % 8);
(&m)->set_f375(3822354744 + (i * 1) % 8);
(&m)->set_f376(1876841178 + (i * 1) % 8);
(&m)->set_f377(816111639 + (i * 1) % 8);
(&m)->set_f378(2037264224 + (i * 1) % 8);
(&m)->set_f379(62579 + (i * 1) % 8);
(&m)->set_f380(880236239 + (i * 1) % 8);
(&m)->set_f381(544991901 + (i * 1) % 8);
(&m)->set_f382(3386400401 + (i * 1) % 8);
(&m)->set_f383(78 + (i * 1) % 8);
(&m)->set_f384(46192 + (i * 1) % 8);
(&m)->set_f385(32 + (i * 1) % 8);
(&m)->set_f386(1134833726 + (i * 1) % 8);
(&m)->set_f387(26559 + (i * 1) % 8);
(&m)->set_f388(7256 + (i * 1) % 8);
(&m)->set_f389(756218325 + (i * 1) % 8);
(&m)->set_f390(61 + (i * 1) % 8);
(&m)->set_f391(1675667099 + (i * 1) % 8);
(&m)->set_f392(50035 + (i * 1) % 8);
(&m)->set_f393(19 + (i * 1) % 8);
(&m)->set_f394(63929 + (i * 1) % 8);
(&m)->set_f395(457458069 + (i * 1) % 8);
(&m)->set_f396(9369 + (i * 1) % 8);
(&m)->set_f397(837244394 + (i * 1) % 8);
(&m)->set_f398(240 + (i * 1) % 8);
(&m)->set_f399(7857270 + (i * 1) % 8);
(&m)->set_f400(2224317767 + (i * 1) % 8);


    messages.push_back(m);
    outs.push_back("");
  }

  //
  // Benchmark serialize.
  //
  // Warm-up.
  for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
    if (!messages[i].SerializeToString(&outs[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }

  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();
  for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
    if (!messages[i].SerializeToString(&outs[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  auto took_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
  std::cout << "serialize took = "
            << took_ns / (messages.size() - kNofWarmUpIterations)
            << " [ns], size = " << outs[0].size() << " Bytes" << std::endl;

  //
  // Benchmark deserialize.
  //
  std::vector<M> messages_out;
  for (size_t i = 0; i < messages.size(); ++i) messages_out.push_back(M());

  // Warm-up.
  for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
    if (!messages_out[i].ParseFromString(outs[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }

  begin = std::chrono::steady_clock::now();
  for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
    if (!messages_out[i].ParseFromString(outs[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }
  end = std::chrono::steady_clock::now();
  took_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
  std::cout << "deserialize took = "
            << took_ns / (messages.size() - kNofWarmUpIterations)
            << " [ns], size = " << outs[0].size() << " Bytes" << std::endl;

  // Compare.
  bool all_correct = true;
  for (size_t i = 0; i < messages.size() && all_correct; ++i)
    all_correct = google::protobuf::util::MessageDifferencer::Equals(
        messages[i], messages_out[i]);
  std::cout << (all_correct ? "ALL CORRECT" : "ERROR: DATA MISSMATCH")
            << std::endl;

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
