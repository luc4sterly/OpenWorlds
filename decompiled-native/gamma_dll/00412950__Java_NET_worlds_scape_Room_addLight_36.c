// 00412950 _Java_NET_worlds_scape_Room_addLight@36 [Global]
// program: gamma.dll

int _Java_NET_worlds_scape_Room_addLight_36
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined4 param_9)

{
  int iVar1;
  
                    /* 0x12950  272  _Java_NET_worlds_scape_Room_addLight@36 */
  iVar1 = FUN_00418fc0(param_4,param_5,param_6);
  if (iVar1 == 0) {
    FUN_00402800(s_nRoom_0046f560,0x7d);
  }
  FUN_00419e30(iVar1,param_7,param_8,param_9);
  FUN_00418e00(param_3,iVar1);
  return iVar1;
}


