// 10069bd4 FUN_10069bd4 [Global]
// program: RWDL6D21.DLL

void FUN_10069bd4(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)*param_1;
  DAT_1007fc50 = param_2;
  DAT_1007fc4c = DAT_1007f5a0 - param_2;
  do {
    uVar2 = DAT_1007fc50;
    if (0x10 < (int)DAT_1007fc50) {
      uVar2 = DAT_1007fc50 >> 4;
      do {
        bVar1 = (char)uVar2 - 1;
        uVar2 = (uint)bVar1;
      } while (bVar1 != 0);
      for (uVar2 = DAT_1007fc50 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = param_4;
        puVar3 = puVar3 + 1;
      }
      uVar2 = DAT_1007fc50 & 3;
    }
    for (uVar2 = uVar2 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(short *)puVar3 = (short)param_4;
      puVar3 = (undefined4 *)((int)puVar3 + 2);
    }
    puVar3 = (undefined4 *)((int)puVar3 + DAT_1007fc4c);
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}


