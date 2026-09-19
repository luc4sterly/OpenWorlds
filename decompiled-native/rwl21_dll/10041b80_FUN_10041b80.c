// 10041b80 FUN_10041b80 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10041b80(int param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)(param_1 + 0x74);
  if (*(int *)(param_1 + 0x8c) != 2) {
    pfVar2 = param_2;
  }
  *(float *)(param_1 + 0x80) = *pfVar2;
  *(float *)(param_1 + 0x84) = pfVar2[1];
  fVar1 = pfVar2[1] - *pfVar2;
  if (fVar1 <= (float)_DAT_100522c8) {
    fVar1 = 1.0;
  }
  fVar1 = (float)_DAT_100522d8 / fVar1;
  if (*(int *)(param_1 + 0x218) == 1) {
    fVar1 = fVar1 * *pfVar2;
  }
  *(float *)(param_1 + 0x88) = fVar1;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x2e4) = 0;
  return;
}


