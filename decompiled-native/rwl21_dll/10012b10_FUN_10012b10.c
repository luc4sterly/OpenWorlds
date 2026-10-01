// 10012b10 FUN_10012b10 [Global]
// program: RWL21.DLL

bool FUN_10012b10(FILE *param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int extraout_EDX;
  float fVar4;
  float fVar5;
  int local_14;
  float local_10;
  float local_c;
  
  iVar1 = FUN_10020800(param_1,s__f_f_d_1005aaf0);
  if (iVar1 != 3) {
    FUN_1000cba0(5);
    return false;
  }
  iVar1 = 0;
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return false;
  }
  iVar2 = FUN_1001d760(local_c,extraout_EDX);
  if (iVar2 != 0) {
    iVar1 = 2;
    fVar5 = 0.0;
    fVar4 = 0.0;
    pfVar3 = (float *)FUN_1001d770();
    FUN_1001c820(pfVar3,fVar4,local_c,fVar5,iVar1);
    iVar1 = RwCone(0.0,local_10,local_14);
    FUN_1001d780();
  }
  return (bool)('\x01' - (iVar1 == 0));
}


