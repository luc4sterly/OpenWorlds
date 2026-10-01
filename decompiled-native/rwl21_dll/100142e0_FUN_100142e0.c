// 100142e0 FUN_100142e0 [Global]
// program: RWL21.DLL

bool FUN_100142e0(FILE *param_1)

{
  int iVar1;
  uint local_18;
  uint local_14;
  uint local_10;
  
  iVar1 = FUN_10020800(param_1,s__f_f_f_1005aab4);
  if (iVar1 == 3) {
    FUN_1001ba80();
    iVar1 = RwCurrentMaterial();
    iVar1 = RwSetMaterialColor(iVar1,local_10,local_14,local_18);
    return (bool)('\x01' - (iVar1 == 0));
  }
  FUN_1000cba0(5);
  return false;
}


