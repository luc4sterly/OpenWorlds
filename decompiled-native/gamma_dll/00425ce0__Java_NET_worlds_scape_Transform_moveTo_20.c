// 00425ce0 _Java_NET_worlds_scape_Transform_moveTo@20 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_scape_Transform_moveTo_20
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
                    /* 0x25ce0  327  _Java_NET_worlds_scape_Transform_moveTo@20 */
  uVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00419f50(uVar1,3,0,param_3);
  FUN_00419f50(uVar1,3,1,param_4);
  FUN_00419f50(uVar1,3,2,param_5);
  FUN_00412800(param_1,param_2,DAT_0049d25c);
  return param_2;
}


