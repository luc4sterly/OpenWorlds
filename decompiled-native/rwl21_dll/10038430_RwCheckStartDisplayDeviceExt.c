// 10038430 RwCheckStartDisplayDeviceExt [Global]
// programa: RWL21.DLL

undefined4 RwCheckStartDisplayDeviceExt(int param_1,undefined4 param_2,int param_3,int param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  int local_c;
  
                    /* 0x38430  24  RwCheckStartDisplayDeviceExt */
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    if ((*(int *)(param_1 + 0x274) != 0) && (*(int *)(param_1 + 0x278) != 0)) {
      uVar2 = (**(code **)(param_1 + 0x278))(param_1,param_2,param_3,param_4);
      for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
        puVar1 = (uint *)(param_4 + local_c * 8);
        *puVar1 = *puVar1 & 0x7fffffff;
      }
      return uVar2;
    }
    FUN_1000cba0(0x4e);
  }
  return 0;
}


