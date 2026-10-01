// 00413490 _Java_NET_worlds_scape_WObject_getClumpBBox@16 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_WObject_getClumpBBox_16
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_24 [3];
  undefined4 local_18 [3];
  
                    /* 0x13490  353  _Java_NET_worlds_scape_WObject_getClumpBBox@16 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 != 0) {
    FUN_00419360(iVar1,local_24,local_18);
    FUN_0041ab00(param_1,param_3,local_24);
    FUN_0041ab00(param_1,param_4,local_18);
  }
  return;
}


