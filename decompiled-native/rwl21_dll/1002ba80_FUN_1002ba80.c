// 1002ba80 FUN_1002ba80 [Global]
// program: RWL21.DLL

void FUN_1002ba80(uint *param_1)

{
  uint uVar1;
  
  FUN_1002baf0(param_1);
  uVar1 = param_1[0x11];
  if (uVar1 != 1) {
    if (uVar1 == 2) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1[0x13]);
      param_1[0x13] = 0;
      param_1[0x12] = 0;
    }
    else if (uVar1 != 3) {
      FUN_1000cba0(0x65);
    }
  }
  param_1[0x11] = 0;
  FUN_10037010(DAT_1005adac,param_1);
  return;
}


