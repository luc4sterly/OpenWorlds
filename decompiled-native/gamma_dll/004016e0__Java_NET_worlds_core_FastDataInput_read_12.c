// 004016e0 _Java_NET_worlds_core_FastDataInput_read@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_core_FastDataInput_read_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  LPCSTR pCVar1;
  uint *this;
  
                    /* 0x16e0  121  _Java_NET_worlds_core_FastDataInput_read@12 */
  pCVar1 = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  this = FUN_0044e010(0x14);
  if (this != (uint *)0x0) {
    FUN_00401540(this,pCVar1);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pCVar1);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489024,this);
  if ((byte *)this[3] != (byte *)0x0) {
    FUN_00402930(param_1,(byte *)this[3],this[4]);
  }
  return;
}


