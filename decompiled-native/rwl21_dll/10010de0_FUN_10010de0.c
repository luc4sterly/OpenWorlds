// 10010de0 FUN_10010de0 [Global]
// programa: RWL21.DLL

bool FUN_10010de0(FILE *param_1)

{
  int iVar1;
  float *pfVar2;
  float local_18;
  float local_14;
  float local_10;
  
  iVar1 = FUN_10020800(param_1,s__f_f_f_1005aab4);
  if (iVar1 == 3) {
    iVar1 = 2;
    pfVar2 = (float *)FUN_1001d770();
    iVar1 = FUN_1001c940(pfVar2,local_10,local_14,local_18,iVar1);
    return (bool)('\x01' - (iVar1 == 0));
  }
  FUN_1000cba0(5);
  return false;
}


