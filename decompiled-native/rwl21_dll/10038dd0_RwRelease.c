// 10038dd0 RwRelease [Global]
// program: RWL21.DLL

void RwRelease(void)

{
                    /* 0x38dd0  331  RwRelease */
  if (DAT_1005b754 == 0) {
    FUN_1000cba0(0x55);
  }
  else {
    if (DAT_1005b74c != 0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(DAT_1005b74c);
      DAT_1005b74c = 0;
    }
    FUN_100205a0();
    FUN_10041b40();
    FUN_100166b0();
    FUN_100308e0();
    FUN_1000ea40();
    FUN_1000c940();
    FUN_10009780();
    FUN_1001ec30();
    FUN_10036f40();
    FUN_100195b0();
    FUN_10042b50();
    FUN_10027420();
    FUN_10034070();
    FUN_10002690();
    FUN_1001bc30();
    FUN_10020b30();
    FUN_1001e860();
    FUN_1001e710();
    FUN_100416e0();
    FUN_10041860();
    FUN_10037100();
    FUN_10031190();
  }
  return;
}


