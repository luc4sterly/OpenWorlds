// 00402f40 _Java_NET_worlds_core_Std_instanceOf@16 [Global]
// programa: gamma.dll

uint _Java_NET_worlds_core_Std_instanceOf_16
               (int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint in_EAX;
  uint uVar1;
  
                    /* 0x2f40  163  _Java_NET_worlds_core_Std_instanceOf@16 */
  if (param_3 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x80))(param_1,param_3,param_4);
    return uVar1;
  }
  return in_EAX & 0xffffff00;
}


