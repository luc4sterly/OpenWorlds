// 00402f70 _Java_NET_worlds_core_Std_getenv@12 [Global]
// programa: gamma.dll

undefined4 _Java_NET_worlds_core_Std_getenv_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
                    /* 0x2f70  162  _Java_NET_worlds_core_Std_getenv@12 */
  pbVar1 = (byte *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  pbVar2 = FUN_00450b80(pbVar1);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pbVar1);
  if (pbVar2 == (byte *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0x29c))(param_1,pbVar2);
  }
  return uVar3;
}


