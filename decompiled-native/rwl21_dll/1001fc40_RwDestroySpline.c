// 1001fc40 RwDestroySpline [Global]
// program: RWL21.DLL

undefined4 RwDestroySpline(int param_1)

{
                    /* 0x1fc40  66  RwDestroySpline */
  if (param_1 != 0) {
    (**(code **)(PTR_DAT_1005b69c + 0x358))(*(undefined4 *)(param_1 + 0xc));
    (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
    return 1;
  }
  FUN_1000cba0(1);
  return 0;
}


