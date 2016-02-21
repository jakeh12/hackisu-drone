#include <avr/pgmspace.h>

const int exp_table[1441] PROGMEM = {
  700,
  701,
  703,
  704,
  706,
  708,
  709,
  711,
  713,
  714,
  716,
  718,
  719,
  721,
  722,
  724,
  726,
  727,
  729,
  730,
  732,
  733,
  735,
  737,
  738,
  740,
  741,
  743,
  744,
  746,
  747,
  749,
  750,
  752,
  754,
  755,
  757,
  758,
  760,
  761,
  763,
  764,
  765,
  767,
  768,
  770,
  771,
  773,
  774,
  776,
  777,
  779,
  780,
  781,
  783,
  784,
  786,
  787,
  789,
  790,
  791,
  793,
  794,
  796,
  797,
  798,
  800,
  801,
  802,
  804,
  805,
  807,
  808,
  809,
  811,
  812,
  813,
  815,
  816,
  817,
  819,
  820,
  821,
  823,
  824,
  825,
  826,
  828,
  829,
  830,
  832,
  833,
  834,
  835,
  837,
  838,
  839,
  840,
  842,
  843,
  844,
  845,
  847,
  848,
  849,
  850,
  851,
  853,
  854,
  855,
  856,
  857,
  859,
  860,
  861,
  862,
  863,
  865,
  866,
  867,
  868,
  869,
  870,
  871,
  873,
  874,
  875,
  876,
  877,
  878,
  879,
  881,
  882,
  883,
  884,
  885,
  886,
  887,
  888,
  889,
  890,
  891,
  893,
  894,
  895,
  896,
  897,
  898,
  899,
  900,
  901,
  902,
  903,
  904,
  905,
  906,
  907,
  908,
  909,
  910,
  911,
  912,
  913,
  914,
  915,
  916,
  917,
  918,
  919,
  920,
  921,
  922,
  923,
  924,
  925,
  926,
  927,
  928,
  929,
  930,
  931,
  932,
  933,
  934,
  934,
  935,
  936,
  937,
  938,
  939,
  940,
  941,
  942,
  943,
  944,
  944,
  945,
  946,
  947,
  948,
  949,
  950,
  951,
  951,
  952,
  953,
  954,
  955,
  956,
  957,
  957,
  958,
  959,
  960,
  961,
  961,
  962,
  963,
  964,
  965,
  966,
  966,
  967,
  968,
  969,
  970,
  970,
  971,
  972,
  973,
  973,
  974,
  975,
  976,
  976,
  977,
  978,
  979,
  979,
  980,
  981,
  982,
  982,
  983,
  984,
  985,
  985,
  986,
  987,
  988,
  988,
  989,
  990,
  990,
  991,
  992,
  992,
  993,
  994,
  995,
  995,
  996,
  997,
  997,
  998,
  999,
  999,
  1000,
  1001,
  1001,
  1002,
  1002,
  1003,
  1004,
  1004,
  1005,
  1006,
  1006,
  1007,
  1008,
  1008,
  1009,
  1009,
  1010,
  1011,
  1011,
  1012,
  1012,
  1013,
  1014,
  1014,
  1015,
  1015,
  1016,
  1017,
  1017,
  1018,
  1018,
  1019,
  1020,
  1020,
  1021,
  1021,
  1022,
  1022,
  1023,
  1023,
  1024,
  1025,
  1025,
  1026,
  1026,
  1027,
  1027,
  1028,
  1028,
  1029,
  1029,
  1030,
  1030,
  1031,
  1031,
  1032,
  1032,
  1033,
  1033,
  1034,
  1034,
  1035,
  1035,
  1036,
  1036,
  1037,
  1037,
  1038,
  1038,
  1039,
  1039,
  1040,
  1040,
  1041,
  1041,
  1042,
  1042,
  1043,
  1043,
  1043,
  1044,
  1044,
  1045,
  1045,
  1046,
  1046,
  1047,
  1047,
  1047,
  1048,
  1048,
  1049,
  1049,
  1050,
  1050,
  1050,
  1051,
  1051,
  1052,
  1052,
  1052,
  1053,
  1053,
  1054,
  1054,
  1054,
  1055,
  1055,
  1055,
  1056,
  1056,
  1057,
  1057,
  1057,
  1058,
  1058,
  1058,
  1059,
  1059,
  1060,
  1060,
  1060,
  1061,
  1061,
  1061,
  1062,
  1062,
  1062,
  1063,
  1063,
  1063,
  1064,
  1064,
  1064,
  1065,
  1065,
  1065,
  1066,
  1066,
  1066,
  1067,
  1067,
  1067,
  1068,
  1068,
  1068,
  1068,
  1069,
  1069,
  1069,
  1070,
  1070,
  1070,
  1071,
  1071,
  1071,
  1071,
  1072,
  1072,
  1072,
  1073,
  1073,
  1073,
  1073,
  1074,
  1074,
  1074,
  1074,
  1075,
  1075,
  1075,
  1075,
  1076,
  1076,
  1076,
  1076,
  1077,
  1077,
  1077,
  1077,
  1078,
  1078,
  1078,
  1078,
  1079,
  1079,
  1079,
  1079,
  1080,
  1080,
  1080,
  1080,
  1080,
  1081,
  1081,
  1081,
  1081,
  1082,
  1082,
  1082,
  1082,
  1082,
  1083,
  1083,
  1083,
  1083,
  1083,
  1084,
  1084,
  1084,
  1084,
  1084,
  1084,
  1085,
  1085,
  1085,
  1085,
  1085,
  1086,
  1086,
  1086,
  1086,
  1086,
  1086,
  1087,
  1087,
  1087,
  1087,
  1087,
  1087,
  1088,
  1088,
  1088,
  1088,
  1088,
  1088,
  1089,
  1089,
  1089,
  1089,
  1089,
  1089,
  1089,
  1090,
  1090,
  1090,
  1090,
  1090,
  1090,
  1090,
  1091,
  1091,
  1091,
  1091,
  1091,
  1091,
  1091,
  1091,
  1092,
  1092,
  1092,
  1092,
  1092,
  1092,
  1092,
  1092,
  1092,
  1093,
  1093,
  1093,
  1093,
  1093,
  1093,
  1093,
  1093,
  1093,
  1094,
  1094,
  1094,
  1094,
  1094,
  1094,
  1094,
  1094,
  1094,
  1094,
  1095,
  1095,
  1095,
  1095,
  1095,
  1095,
  1095,
  1095,
  1095,
  1095,
  1095,
  1095,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1096,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1097,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1098,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1099,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1100,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1101,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1102,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1103,
  1104,
  1104,
  1104,
  1104,
  1104,
  1104,
  1104,
  1104,
  1104,
  1104,
  1104,
  1104,
  1105,
  1105,
  1105,
  1105,
  1105,
  1105,
  1105,
  1105,
  1105,
  1105,
  1106,
  1106,
  1106,
  1106,
  1106,
  1106,
  1106,
  1106,
  1106,
  1107,
  1107,
  1107,
  1107,
  1107,
  1107,
  1107,
  1107,
  1107,
  1108,
  1108,
  1108,
  1108,
  1108,
  1108,
  1108,
  1108,
  1109,
  1109,
  1109,
  1109,
  1109,
  1109,
  1109,
  1110,
  1110,
  1110,
  1110,
  1110,
  1110,
  1110,
  1111,
  1111,
  1111,
  1111,
  1111,
  1111,
  1112,
  1112,
  1112,
  1112,
  1112,
  1112,
  1113,
  1113,
  1113,
  1113,
  1113,
  1113,
  1114,
  1114,
  1114,
  1114,
  1114,
  1115,
  1115,
  1115,
  1115,
  1115,
  1115,
  1116,
  1116,
  1116,
  1116,
  1116,
  1117,
  1117,
  1117,
  1117,
  1117,
  1118,
  1118,
  1118,
  1118,
  1119,
  1119,
  1119,
  1119,
  1119,
  1120,
  1120,
  1120,
  1120,
  1121,
  1121,
  1121,
  1121,
  1122,
  1122,
  1122,
  1122,
  1123,
  1123,
  1123,
  1123,
  1124,
  1124,
  1124,
  1124,
  1125,
  1125,
  1125,
  1125,
  1126,
  1126,
  1126,
  1126,
  1127,
  1127,
  1127,
  1128,
  1128,
  1128,
  1128,
  1129,
  1129,
  1129,
  1130,
  1130,
  1130,
  1131,
  1131,
  1131,
  1131,
  1132,
  1132,
  1132,
  1133,
  1133,
  1133,
  1134,
  1134,
  1134,
  1135,
  1135,
  1135,
  1136,
  1136,
  1136,
  1137,
  1137,
  1137,
  1138,
  1138,
  1138,
  1139,
  1139,
  1139,
  1140,
  1140,
  1141,
  1141,
  1141,
  1142,
  1142,
  1142,
  1143,
  1143,
  1144,
  1144,
  1144,
  1145,
  1145,
  1145,
  1146,
  1146,
  1147,
  1147,
  1147,
  1148,
  1148,
  1149,
  1149,
  1149,
  1150,
  1150,
  1151,
  1151,
  1152,
  1152,
  1152,
  1153,
  1153,
  1154,
  1154,
  1155,
  1155,
  1156,
  1156,
  1156,
  1157,
  1157,
  1158,
  1158,
  1159,
  1159,
  1160,
  1160,
  1161,
  1161,
  1162,
  1162,
  1163,
  1163,
  1164,
  1164,
  1165,
  1165,
  1166,
  1166,
  1167,
  1167,
  1168,
  1168,
  1169,
  1169,
  1170,
  1170,
  1171,
  1171,
  1172,
  1172,
  1173,
  1173,
  1174,
  1174,
  1175,
  1176,
  1176,
  1177,
  1177,
  1178,
  1178,
  1179,
  1179,
  1180,
  1181,
  1181,
  1182,
  1182,
  1183,
  1184,
  1184,
  1185,
  1185,
  1186,
  1187,
  1187,
  1188,
  1188,
  1189,
  1190,
  1190,
  1191,
  1191,
  1192,
  1193,
  1193,
  1194,
  1195,
  1195,
  1196,
  1197,
  1197,
  1198,
  1198,
  1199,
  1200,
  1200,
  1201,
  1202,
  1202,
  1203,
  1204,
  1204,
  1205,
  1206,
  1207,
  1207,
  1208,
  1209,
  1209,
  1210,
  1211,
  1211,
  1212,
  1213,
  1214,
  1214,
  1215,
  1216,
  1217,
  1217,
  1218,
  1219,
  1220,
  1220,
  1221,
  1222,
  1223,
  1223,
  1224,
  1225,
  1226,
  1226,
  1227,
  1228,
  1229,
  1229,
  1230,
  1231,
  1232,
  1233,
  1233,
  1234,
  1235,
  1236,
  1237,
  1238,
  1238,
  1239,
  1240,
  1241,
  1242,
  1242,
  1243,
  1244,
  1245,
  1246,
  1247,
  1248,
  1248,
  1249,
  1250,
  1251,
  1252,
  1253,
  1254,
  1255,
  1255,
  1256,
  1257,
  1258,
  1259,
  1260,
  1261,
  1262,
  1263,
  1264,
  1265,
  1265,
  1266,
  1267,
  1268,
  1269,
  1270,
  1271,
  1272,
  1273,
  1274,
  1275,
  1276,
  1277,
  1278,
  1279,
  1280,
  1281,
  1282,
  1283,
  1284,
  1285,
  1286,
  1287,
  1288,
  1289,
  1290,
  1291,
  1292,
  1293,
  1294,
  1295,
  1296,
  1297,
  1298,
  1299,
  1300,
  1301,
  1302,
  1303,
  1304,
  1305,
  1306,
  1308,
  1309,
  1310,
  1311,
  1312,
  1313,
  1314,
  1315,
  1316,
  1317,
  1318,
  1320,
  1321,
  1322,
  1323,
  1324,
  1325,
  1326,
  1328,
  1329,
  1330,
  1331,
  1332,
  1333,
  1334,
  1336,
  1337,
  1338,
  1339,
  1340,
  1342,
  1343,
  1344,
  1345,
  1346,
  1348,
  1349,
  1350,
  1351,
  1352,
  1354,
  1355,
  1356,
  1357,
  1359,
  1360,
  1361,
  1362,
  1364,
  1365,
  1366,
  1367,
  1369,
  1370,
  1371,
  1373,
  1374,
  1375,
  1376,
  1378,
  1379,
  1380,
  1382,
  1383,
  1384,
  1386,
  1387,
  1388,
  1390,
  1391,
  1392,
  1394,
  1395,
  1397,
  1398,
  1399,
  1401,
  1402,
  1403,
  1405,
  1406,
  1408,
  1409,
  1410,
  1412,
  1413,
  1415,
  1416,
  1418,
  1419,
  1420,
  1422,
  1423,
  1425,
  1426,
  1428,
  1429,
  1431,
  1432,
  1434,
  1435,
  1436,
  1438,
  1439,
  1441,
  1442,
  1444,
  1445,
  1447,
  1449,
  1450,
  1452,
  1453,
  1455,
  1456,
  1458,
  1459,
  1461,
  1462,
  1464,
  1466,
  1467,
  1469,
  1470,
  1472,
  1473,
  1475,
  1477,
  1478,
  1480,
  1481,
  1483,
  1485,
  1486,
  1488,
  1490,
  1491,
  1493,
  1495,
  1496,
  1498,
  1499
 };
