// 1000a2b0 RwDestroyCamera [Global]
// programa: RWL21.DLL

void RwDestroyCamera(undefined4 *param_1)

{
                    /* 0xa2b0  57  RwDestroyCamera */
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)(PTR_DAT_1005b69c + 0x30))(param_1);
  }
  FUN_1000a2d0(param_1);
  return;
}


