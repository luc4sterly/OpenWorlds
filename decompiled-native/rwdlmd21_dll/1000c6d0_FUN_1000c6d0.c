// 1000c6d0 FUN_1000c6d0 [Global]
// programa: rwdlmd21.dll

byte FUN_1000c6d0(byte *param_1,byte *param_2,uint *param_3)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *param_2;
  bVar2 = bVar1 <= *param_1;
  if ((bool)bVar2) {
    *param_3 = (uint)bVar1;
  }
  else {
    param_3[1] = (uint)bVar1;
  }
  bVar1 = param_2[1];
  if (param_1[1] < bVar1) {
    param_3[3] = (uint)bVar1;
  }
  else {
    bVar2 = bVar2 | 2;
    param_3[2] = (uint)bVar1;
  }
  bVar1 = param_2[2];
  if (param_1[2] < bVar1) {
    param_3[5] = (uint)bVar1;
    return bVar2;
  }
  param_3[4] = (uint)bVar1;
  return bVar2 | 4;
}


