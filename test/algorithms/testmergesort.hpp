#ifndef TEST_MERGESORT_H_
#define TEST_MERGESORT_H_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>
#include <vector>
#include <limits>

#include "algorithms/mergesort.hpp"

BOOST_AUTO_TEST_CASE(test_ms_empty_container)
{
    BOOST_CHECK(vector<int>() == MergeSort(vector<int>()));
}

BOOST_AUTO_TEST_CASE(test_ms_one_value)
{
    vector<int> container;
    container.push_back(42);

    BOOST_CHECK(container == MergeSort(container));
}

BOOST_AUTO_TEST_CASE(test_ms_sorted_container)
{
    vector<int> container;
    container.push_back(0);
    container.push_back(42);
    container.push_back(43);
    container.push_back(100);

    BOOST_CHECK(container == MergeSort(container));
}

BOOST_AUTO_TEST_CASE(test_ms_min_max_int_values)
{
    vector<int> container;
    container.push_back(42);
    container.push_back(10);
    container.push_back(1);
    container.push_back(std::numeric_limits<int>::min());
    container.push_back(std::numeric_limits<int>::max());

    vector<int> result = container;
    std::sort(result.begin(), result.end());

    BOOST_CHECK(result == MergeSort(container));
}

BOOST_AUTO_TEST_CASE(test_ms_positive_negative_values)
{
    vector<int> container;
    container.push_back(42);
    container.push_back(-10);
    container.push_back(1);
    container.push_back(0);
    container.push_back(-1000);

    vector<int> result = container;
    std::sort(result.begin(), result.end());

    BOOST_CHECK(result == MergeSort(container));
}

BOOST_AUTO_TEST_CASE(test_ms_duplicate_values)
{
    vector<int> container;
    container.push_back(42);
    container.push_back(1);
    container.push_back(1);
    container.push_back(10);
    container.push_back(43);
    container.push_back(10);

    vector<int> result = container;
    std::sort(result.begin(), result.end());

    BOOST_CHECK(result == MergeSort(container));
}

BOOST_AUTO_TEST_CASE(test_ms_many_values)
{
    vector<int> container = {
        3717, 1783, 2358, 4043, -2286, 1076, -3712, 1159, 2310, 4732, 4030, 4750,
        1109, 4625, 4799, -3957, -3388, 2224, -3638, 4158, 4948, -4783, -2344, -3815,
        4103, -4789, 1189, -2271, 1493, 4231, -2770, -2574, 1954, 1314, 3222, -479,
        4296, 1162, 4304, -1932, 2610, 3413, 1532, -1243, -4354, -486, -3504, 2514,
        4467, 3670, -792, -43, -2637, -1401, -180, -2968, -1001, 1333, 3220, -883,
        1415, 496, 4512, 2463, -4918, -817, 3168, -2774, -638, 119, -3598, 2097,
        -1286, -393, 1315, 2250, -625, 1680, 4417, 2014, 819, -1939, -3563, -3586,
        -896, -1119, -532, 1482, -1411, -2669, -4050, 1085, 1892, 3923, 36, 4575,
        2981, -1084, -3293, 2702, 1972, 68, 4911, 3957, 4055, 4381, 3219, -3313,
        -2786, -3600, 3691, 1433, -876, -1168, -2003, 3523, 3895, -1040, -4624, 4832,
        -3063, -901, -4778, -1541, -3678, 2034, -3523, -3123, 3491, -4143, 4966, 4667,
        -2078, -4397, 2083, -570, -3939, -3520, -1347, 1449, 386, -3937, 1638, -4090,
        2539, 2653, 1313, -4730, 3164, -2558, 4531, 159, 2710, 3067, 78, -4538, -1237,
        4717, 4000, 2369, -2864, 2670, -759, -544, -208, 1976, -882, 426, -3916,
        -2364, 3228, 4190, -1816, -1782, -1394, -1596, -140, 711, 1925, 3238,
        -2037, -1949, -3521, 4191, 57, 2269, 4440, 1214, -4393, 378, -2773, 3076,
        579, 4121, -4232, 4840, -3899, 4300, -1755, -1343, 2231, -614, 3433,
        490, 264, -1883, -219, -4069, -854, 3289, -2536, 4472, 1307, 1978, 3927,
        -1266, 2139, -1028, -1128, 4696, 4436, -2600, 4729, -181, 4453, -432,
        1198, 3485, 2394, -1368, 261, -3347, 4510, -3439, -3838, -867, -910,
        4882, 2435, -1468, 4834, 199, -1171, -936, -4590, -809, 178, -1400, -2229,
        -1773, 173, 2115, 2571, -4997, -739, -2444, -2691, 835, -339, 2768,
        -4473, -4926, -1915, 2916, 2102, -106, 2314, 486, 1164, -1906, -3101,
        4210, 3834, 3369, -1158, 982, -1973, 395, -999, 290, -4705, -1109, -4813,
        -2957, 4847, -3705, 4913, 3807, -3497, -1000, -2778, 1363, -1743, -3137,
        340, -4135, -3685, 4260, 3552, 1173, 864, 2026, -348, -3016, -2598, -507,
        -4940, -1999, 4611, -1273, 2498, 450, -4478, -331, -2575, -2930, -3544,
        -2109, -778, 1255, 914, 4529, -2520, 2681, 3379, -1607, 1285, -2684,
        -4732, -3951, -2342, -2247, -4181, 4379, -3918, 3763, 691, 1223, -4045,
        2206, 4045, 4189, -670, -4579, -2162, 4424, 2068, -564, 2535, 124, -2016,
        3208, -1570, 2764, -236, -3990, 1142, -773, 2650, -161, -1935, -737,
        -4557, 813, -1264, -1103, 3976, -451, 2474, -2320, -1281, 229, 4492,
        -1504, 2549, 1403, 580, 4301, 1130, -439, 1971, -2724, -2918, -1414,
        418, 1025, 4459, 4773, -3312, -2802, -4539, 1728, 1604, 2647, 2010,
        -1854, 4383, 2584, 3891, 1337, -4185, 346, -3247, -3246, -2621, -2194,
        -973, -2792, 2926, 4680, -718, -3297, 1692, 3194, 4256, -3396, -933,
        1980, -4935, 3960, 1329, 3822, -358, -1124, -2076, -2515, -1661, -4615,
        -465, 826, -1037, 4034, -1377, 4211, 4486, 2620, -1355, -470, 2628, 720,
        4462, -4743, 2505, 3901, -4332, -3747, -3978, 24, 777, -2923, 3124, 4996,
        -4056, 1865, -4249, 3545, 2124, 338, 26, 3438, 3370, 3419, 2945, -2698,
        -3914, 3273, 4263, -1184, -3695, 3231, -3421, -4089, 2065, 3309, -3237,
        -3098, -3452, 602, 1015, -4592, 3101, 4011, 1308, -783, -828, 4650, -2188,
        -1132, 2494, -1120, -2917, 995, -4608, 3733, -2059, -1338, -1325, 2262,
        -2272, 2739, -1306, 3832, 4067, -897, 4038, 2294, -642, -4876, -3984,
        -533, -4974, 1612, 238, 2639, -2045, 4382, 4063, -1405, 3281, 4664, -3232,
         -4824, 231, -401, -2754, 3861, 350, -63, 1901, -2218, -4420, 4971, -959,
         -4002, 3884, 4435, -2922, -3302, -893, 3854, 499, -3931, 3005, 2636, 1689,
         1042, 3978, 4269, 900, 4774, 3870, -2738, -2266, 3639, 3783, -2826, 3396,
         3699, -4959, 1513, -1818, -3474, -535, -3085, 228, -4572, 2422, 3025, 1463,
         1704, 801, -352, 4642, -2596, 1983, 3661, 3442, 4346, 160, 2086, 3376, 152,
         696, -4390, -3200, 4162, -4702, 2484, -4583, 1417, 4844, -2939, 1290, 929,
         -57, -61, 1362, 3443, -3886, -3339, 1301, -563, 3837, -3443, -2844, -889,
         -3698, -1455, -3113, 293, 4355, 1172, -328, -3115, -4530, 3196, 4056, -603,
         2733, -148, 3925, -2905, 949, 4917, -947, -531, -666, -1493, 3596, 4784,
         -1164, 2942, -810, -4076, 3474, 2390, 1741, -73, -3763, 752, 1193, 849,
         4668, 3865, -1093, 2633, -4510, -2472, -1520, 2254, -4774, 4214, -2532,
         1095, 1637, -2215, 1283, -3643, 1553, -4529, -3742, -3318, 3203, 2593,
         3863, 4941, -1913, 4060, -4187, 4391, 473, -2298, 2902, 4633, -2092, 1037,
         -595, 354, -530, 1774, 141, -1290, -4380, 521, 3139, -3486, 102, -382,
         -3979, 3476, -2077, -2414, -4041, -2983, -4809, -4335, -2135, 3544,
         -2904, 3128, -502, 1924, -931, -4206, 1331, 4233, 1849, -4419, 3556,
         -3160, 40, -2087, 3744, -185, -3831, -446, -3125, 1584, -4790, -4595,
         3889, -3562, 515, -1305, -2819, 223, 2974, 455, -799, -4763, 4369, -2287,
         4789, -4651, -150, 2658, -4414, 895, 4904, 4102, -234, 3529, 2679, -335,
         380, -1378, 2142, -4967, 4113, 2077, -2807, 3563, 3628, 1349, 861, 462,
         -1815, -2509, 1257, 605, 847, -3680, -4124, 372, 3687, -313, -326, -4027,
         -2367, -1963, -3639, -4519, -4100, 3121, -2083, 1966, 4594, -3749, -1327,
         -319, -320, 4259, -4096, -4736, -2628, 4449, 2414, -2749, -3075, 2547,
         4166, -2589, -3368, -1441, 2084, -3510, -1855, -4950, 1894, 3852, 1785,
         0, -2612, 3818, 2157, 4340, -634, 45, 3336, -781, -3764, 3862, -3010, 1768,
         1620, 698, 1512, 3537, -1490, -2159, -3864, 2082, -2231, -2814, -2866,
         -4145, 2591, -940, -332, -3972, 94, 2464, 3819, 2418, 4951, -1556, -4174,
         -4726, 4458, 4779, -3405, 1412, 452, -4508, -4452, -2499, -4658, -2448,
         -3653, 2033, 3436, 3028, 4690, 4589, -1802, 2015, -4023, -2321, -241, -2855,
         4892, 1866, 4883, -1918, -2413, 3156, -411, -834, -82, 3933, 1000, -4141,
         4739, 4655, 4936, 3805, -1824, -2348, -2897, 355, 2346, 4741, 1277, 4745,
         666, 1287, -2614, -1560, 834, -4481, 3530, -1941, -1831, 2575, -1796, 4651,
         -38, -4748, 1672, 3477, -2376, 4681, 1960, 1424, -2363, -3565, 296, 4092,
         -4276, -4329, 1087, 1617, -2633, -4272, -1756, 3736, 4054, 4893, -1491,
         -1826, -2562, -1804, -1015, 2396, -1845, 4129, 3688, 4006, -3276, -849,
         -3784, -2008, -4862, 787, 3259, 2767, -640, 1443, -4, 675, -2486, -2192,
         -4835, -4782, -2311, 1336, -2026, -1805, -3637, -4166, -1326, 1864, 4066,
         -3801, 329, 3123, -1357, 3363, 1652, 2655, 2244, 3034, 3789, -902, 2754,
         -3457, 2806, 3097, -2931, -667, -344, 3017, 945, -2587, -3097, 1485, 2208,
         4993, -974, 4262, 4349, -504, 2645, 2303, 2805, -2837, -3157, 4864, -2465,
         814, 2763, 1221, 3638, 765, -4153, 1523, 713, 3327, -586, 4975, 4316, -1639,
         3129, 2986, 3181, -655, 1269, 2872, -3603, 607, 2724, 3234, -4692, -333,
         -804, -209, 774, 3946, 3605, -3096, -381, 4401, -660, 3525, 49, -2442,
         4306, 4688, 442, 4542, 2420, 1944, 4380, -287, -3084, -4347, -851, 220,
         2694, 1876, 2160, 2411, 4154, -1604, 405, 545, -1430, 898, 1769, 3704,
         371, 4777, -2505, -4672, 2909, 2640, -3365, -602, -1403, -4713, 2723,
         -4472, -4666, -3287, -4028, 902, 4886, 3288, 4552, 1402, 1939, 3148,
         3074, 2035, 4938, 4335, -3428, -3876, -424, -3174, 3826, -1, -2610,
         838, -1118, 3036, -1563, 2047, -1891, 2119, 884, -2787, 2569, 1912,
         4820, 4236, 268, -3567, 2072, 494, 705, 1026, -1210, -1927, -1495,
         1355, -3697, -4540, 4976, -762, -1768, 715, -4037, 11, -2659, -4228,
         731, -3435, -562, -2219, -2099, 2168, -3500, -3047, -131, 335, 2996,
         2383, -1169, -1565, -3851, -843, 2968, 135, -189, 3207, 425, -1779,
         3986, -1274, 1082, 3982, 3429, -386, 3311, 1137, -417, 4114, -162, 3038,
         -4337, 2618, -1917, 644, -4704, 211, 3737, -813, 1145, -3707, -4879,
         -2982, -3410, -3847, -2924, 1179, 1619, -1476, 3794, -2744, -65, 3690,
         3390, -113, 299, 2714, -4240, -404, 1262, -2733, -2441, -1653, 703, 1467,
         -34, -455, 1234, -3116, -1823, 1797, -1750, 783, -2550, 4442, -4091,
         1053, 1882, 1384, 546, 1614, 600, -3827, 637, -222, -2821, 1773, -1759,
         -3178, -4013, 2518, -4032, 3202, -3061, -2300, 29, 3291, 4815, 4740,
         1351, -88, 4869, -793, 737, -1247, 3109, -4836, 263, -3467, 1224, -2528,
         -627, -3057, -1298, -54, -4309, -3777, 516, -190, -1539, 2570, 1888, -1003,
         -1404, 2039, 3817, 4780, -4164, -84, -3170, 2381, -2211, 276, 3266, -4685,
         -2430, 2468, -197, -4558, -1415, 266, 4276, -617, 1537, 1837, -4962, -1406,
         -1101, -696, 317, -2128, 1903, -4054, 2257, -2230, -2212, -2282, 423,
         -2476, -3626, -2867, 3030, 333, -3909, 1266, -525, 402, -4355, 1143,
         -1448, 4108, -1216, 1021, -22, 3170, 2934, 3937, -3462, 1141, 4087, 477,
         -2970, 3603, -2877, 2568, 2736, -3447, -4378, 4837, 3610, -1252, 716, -19,
         3227, -3974, -2674, -2356, 3421, 1575, 315, -4099, 84, -2379, -3546, 2619,
         -1875, 2879, 3581, 1943, -886, -4715, -1374, -1131, 388, 2897, -3808, 2386,
         -3987, 3378, -2004, 2870, 186, 4727, 677, 3049, -15, 1931, 4776, 1833,
         -4247, -1893, 4136, -2583, 2678, -2704, 3703, 936, -4644, -3649, -3900,
         -3253, -1256, -2254, 624, 3240, -2020, 4988, 939, 3173, 3093, 4187, 470,
         -149, 3584, -3202, -1200, -3514, 1444, -2145, 1036, -3768, -949, -3534,
         -4271, 4937, 3310, 1378, -356, -3117, -124, 1192, -898, -4043, 1248, 3237,
         -336, -3673, -271, -4369, -2204, -581, 2410, 1757, 779, -2235, -1622, 535,
         -4818, -744, 4485, 3920, -1434, -1643, 1133, 642, 791, -3676, -4115, 3277,
         2751, 306, -1791, -3846, -819, -1933, 4880, -1020, -4754, -1308, 4889, 443,
         -1926, -3955, -4581, -107, -573, -3295, -3896, -1621, 4226, 3952, -448,
         3663, 2701, 2799, -4823, 2308, 951, -2382, -1984, 4222, -2635, -996, -3083,
         2594, 4530, -257, -4932, -4257, -3904, -3865, 1573, 2355, -179, -1916,
         -3361, 2533, 479, -4564, 1596, 175, -643, 794, 1152, 3795, 4550, -2175,
         1542, -3234, -3878, -413, 4564, 3672, 627, -2067, 1655, 481, 1267, 1404,
         1068, -785, 2836, -2445, -2843, -3073, 3452, 1702, 2192, -3049, -1678, 165,
         1678, -9, -4413, -1551, 3782, 2796, 3520, -4234, -829, 3323, -3647, -2622,
         2923, -846, 1673, 3304, 2490, -669, 4939, -3151, -3279, -2576, -4667,
         -4877, -1872, -4204, -1472, 4626, -3423, -243, 4665, -2279, -238, 248,
         -576, 2821, 1676, 1296, -288, -3207, 1353, -2750, -4325, 3295, 1558, 4865,
         28, -841, -1944, 2982, 998, 252, -3367, 3570, -1236, -3079, 1147, 3543,
         -2082, -3455, 3141, -2299, 4802, -4169, -4645, 4950, -619, -997, -2657,
         -1249, -3849, 919, -4287, 23, 2577, 3320, 4658, -1911, 1388, 2487, 408,
         1933, 1480, 153, -3408, -1201, 1394, -2714, 3432, -3606, 3301, -1262,
         1852, 2753, 1742, -4326, 4811, -1285, 3938, 661, 1651, 4613, 1242, -4513,
         -1153, 136, -2852, 3893, -3548, 4294, 2172, 1872, 3954, 3625, 1744, -2161,
         -2421, -303, 4565, -4632, 366, 2286, 3918, -118, -4662, -3980, 4352, 2838,
         123, 1563, -3660, -1811, -1931, -657, -2387, 1175, -2945, 2556, -3992, 1508,
         -4112, 2349, -3796, -4011, 2173, -1134, 189, 2101, -2165, -2992, -4113,
         -1497, -3031, 1486, 3193, -671, -732, 1250, -1668, 1603, -3288, -4509,
         -187, 3838, 1749, 244, -3290, 2715, -4964, 2129, 4653, -2785, 1845, 3078,
         -3336, -3304, -3792, -2969, -4948, -1789, 2492, 4471, -1569, 2057, 2345,
         3423, -108, -515, -2084, -3861, -3817, -4466, 1123, 651, 1525, 753, 3244,
         -4671, -2200, -1508, 4185, -116, -826, -1711, 520, 4450, 1697, -1559,
         -4259, 1840, 4955, 58, -2495, 1098, -2358, -4342, -825, 1411, 15, 3347,
         -1519, 4448, -2854, -1808, -178, -4151, 4829, -402, -4180, 1484, 2449, 170,
         2747, 730, 957, -600, -2075, -3301, 2804, -1065, 2745, 3403, -4207, 4816,
         240, 964, 980, 3290, 2277, 4806, 2624, -2214, -3922, 4069, -4349, -3952,
         -1597, -1111, -512, -3671, 343, -585, 319, -748, 4094, -4084, -3873, -4902,
         -509, -895, -911, -4534, -4226, 3970, 2133, -2623, 226, 534, 3979, -4193,
         2348, -3186, -4291, 325, 1874, -70, -1521, 802, -1898, -3416, 2222, 3116,
         -929, -500, 3824, -3105, 1905, 3375, -4629, 2096, -3721, 456, -4313, 385,
         4500, 2666, -4165, 1339, -1976, 4178, -2236, -4127, -3670, 4620, 538, -1672,
         1755, 1244, 3192, -3254, -3216, -123, -353, 4858, -4000, -3943, -560, 937,
         -1602, 2538, 2922, -875, 4636, 183, 429, 1007, -490, -4630, -4116, 1416,
         4271, -2388, -3663, -2742, 4224, 1211, -2361, 1219, -216, -661, 3041, 4712,
         2703, 387, -4594, -4652, -1458, 471, -1348, -3816, -984, -2240, 3777, -276,
         844, -3483, -1923, -2737, -1853, -3580, 4957, 4644, 854, -1908, 3425, 2654,
         -4492, -2573, 184, 66, -3189, -1412, 4179, 3434, 2486, 740, -3985, -2022,
         -2371, -4437, 326, -1859, 4703, 3559, -822, -437, -3146, -3199, -3492, 4151,
         -2025, 866, -2857, -4987, 771, 2045, -2375, 1372, -3855, 1950, -312, 610,
         -1690, 2234, -26, -2094, 645, -442, 3015, -2803, 2728, -3431, -508, -4253,
         176, 2519, -1320, 2389, 3144, 2845, -2816, -2766, -2096, -174, 1154, -2054,
         -2829, -808, -3045, -3553, 251, -3343, -1142, -2108, -4459, 639, 4420, 706,
         3575, -536, 2680, 2852, -405, -145, -4125, -4665, -3496, 3334, -3926, 1498,
         -67, -273, -2196, 2746, 2054, 2671, 1008, -1379, -2012, -2470, 3695, 4116,
         734, 1327, 4548, 4656, 1207, -2568, -920, 4347, -3376, 2752, 4660, -3377,
         -2527, -4998, -3267, -597, 334, 3994, 3931, 3877, -633, -2977, 1602, 4615,
         -1066, -5, -4725, -555, 421, 3437, 806, -1650, 2337, 3494, 2194, -3219,
         1577, 4305, 2989, -3233, 4584, 3762, 116, -1018, 4901, 79, -3967, 3726,
         3567, 76, 1766, 640, -3717, 2421, 3072, 1357, 1986, -2169, -4690, 1527,
         2762, 3840, -1744, -441, -3353, 2765, 3793, 2440, 2373, -261, 2778, 1811,
         -4556, -4516, 1918, 3232, -2477, -2832, 3114, 1664, 3963, -2646, 1083, 2586,
         -3620, 2827, -990, 1822, 564, -2380, -604, -4874, -751, 2105, 262, -4759,
         -4922, 612, -2178, -1606, -4856, 4756, -3143, -4527, 4451, 1645, -4566,
         4683, 3797, 4322, -3487, -872, -132, 1405, -4942, -2220, 1239, 2331, -3350,
         -4989, 4645, -802, 1425, -3787, -4487, -3087, -252, 681, 1646, -4203, -1449,
         -1857, 4637, 764, -2898, -4261, 4371, 2162, 1695, 2969, 1772, 3810, -703,
         -4784, 2801, 2415, 4949, 3867, 2738, 2667, 82, 2226, -966, 4240, 3727, 3647,
         -481, 2908, 2956, 2351, 3297, -1651, -3545, 1447, -1950, 3816, 1120, 3619,
         1762, -136, -678, 4444, -1895, -3954, -2182, 2507, 1511, -1634, -1011,
         -406, 4119, -325, -1113, -2966, 2877, -4580, -3661, 4318, -924, -3669,
         732, 4175, 3579, -3632, 577, 3965, 321, -4898, 620, 1150, -258, 3593,
         -818, 3752, -1199, 3450, 2841, -4317, 1392, 1138, -1554, 3551, -2984,
         -4767, 773, -2283, -122, 2041, -2538, -412, 2242, 4885, 3785, 2727, 50,
         4597, -4264, -1512, -1638, 451, -4956, 2284, 1957, -1948, -4404, -3006,
         -2427, 1549, 4297, -1362, 3122, 1656, 1618, -2201, -1089, 1430, -4758,
         -4265, 2448, 723, -2827, 4699, 3127, 156, -3571, -1728, -4911, -1043,
         -2243, -92, -977, -2291, 2919, -226, 1181, 4161, -1502, 1104, -4694, 2238,
         1547, -1737, 3465, 2776, 846, -3369, 4504, 3457, -2233, -3820, 749, -4432,
         -2265, -1555, -4675, 2228, 2648, 1624, 4320, -4263, 4490, -812, -3681,
         3009, -2115, -4994, -4749, -914, -3509, -3720, -4731, -506, 3280, -1955,
         4628, -2113, -4476, -2110, -4188, 20, 72, 4714, -4896, 4775, 1093, 1889,
         4960, -4827, 2229, 601, 2578, 3047, 1195, -2021, -1336, 4317, 899, 10,
         878, 4768, -1179, 827, 2824, 1570, 2615, 1052, -3074, 3418, 798, -1390,
         -3726, 2092, -2861, -4255, 1033, -4547, 3644, -191, -3760, 4684, 1842,
         3757, -1675, 4772, 1002, -1899, -3711, -4858, -454, -337, 3845, -3776,
         2189, 842, -2206, -53, -2570, 1347, -1096, -3438, -2636, 2967, -3056,
         852, -2648, 655, -1688, -1226, -1087, -1213, 4760, -3126, -1300, 1920,
         4765, 2557, -1717, 2289, -1969, 4697, 1887, 420, -2888, 4888, -4860,
         -3682, -1894, 1391, -3060, -2946, -3459, -3040, 4535, -4222, -2010, 498,
         2438, 4351, -3779, 552, 3847, -1447, 1879, 830, -2085, 2446, 1694,
         -4442, 1062, -3924, -143, 2106, 2600, 1156, -1244, 328, -796, -1501,
         -4283, 531, 3198, 2917, -1219, 370, -518, -281, 2088, 1271, -3769, 85,
         -2741, 3705, -1341, -4199, 3211, -220, -254, -618, 4841, -1966, 2488,
         -539, 2320, -3824, -3913, -244, 1579, -3283, -396, 1188, 4266, 4511, 52,
         -3030, 4863, -1904, 1167, -4895, -3148, -2316, -48, 2802, 2163, -76,
         -3938, -20, 2906, 2048, -375, -4673, -39, 1824, 4871, -3884, 2433, 3730,
         -3449, -2262, -228, -477, 4384, -93, 2218, 2943, 1366, -3468, -2641, -1030,
         -853, -196, -4286, 1118, -2765, -4009, 1544, -1761, -3005, 3738, 1715,
         761, 3483, -3286, 3540, 222, -2482, -4242, 2874, 291, -1862, -452, -1876,
         2737, -3478, -3511, 3710, 4902, -2850, 1582, 687, -2058, -2088, 3622,
         -3761, -975, -2675, -1769, 4203, -2529, 174, 3178, 3006, -2661, -4211,
         -3118, -861, 3350, -1719, -2688, -994, 3984, 2980, 3279, 3435, 2456,
         -3308, -3141, 1740, 1273, 2646, 3213, -4398, 3062, -2312, -4049, 3538
    };

    vector<int> result = container;
    std::sort(result.begin(), result.end());

    BOOST_CHECK(result == MergeSort(container));
}

#endif /* TEST_MERGESORT_H_ */
