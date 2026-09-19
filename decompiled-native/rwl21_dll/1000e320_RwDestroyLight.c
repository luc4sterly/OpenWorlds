// 1000e320 RwDestroyLight [Global]
// programa: RWL21.DLL

undefined4 RwDestroyLight(int *param_1)

{
  byte bVar1;
  int iVar2;
  
                    /* 0xe320  60  RwDestroyLight */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  bVar1 = -(param_1[0x21] == 2) & 2;
  if (bVar1 == 1) {
    param_1[0x21] = 2;
    FUN_1002c340(param_1);
    iVar2 = RwGetLightOwner((int)param_1);
    FUN_1002c320(iVar2);
  }
  else if (bVar1 == 2) {
    param_1[0x21] = 1;
    FUN_1002c340(param_1);
    iVar2 = RwGetLightOwner((int)param_1);
    FUN_1002c320(iVar2);
  }
  FUN_1002c410(param_1);
  FUN_10037010(DAT_1005a0a8,param_1);
  return 1;
}


