// 00425b60 _Java_NET_worlds_scape_Transform_postHelper@12 [Global]
// program: gamma.dll

undefined4
_Java_NET_worlds_scape_Transform_postHelper_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
                    /* 0x25b60  330  _Java_NET_worlds_scape_Transform_postHelper@12 */
  uVar1 = (**(code **)(*param_1 + 400))(param_1,param_3,DAT_0049d24c);
  uVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00418cb0(uVar2,uVar1);
  FUN_00412800(param_1,param_2,DAT_0049d25c);
  return param_2;
}


