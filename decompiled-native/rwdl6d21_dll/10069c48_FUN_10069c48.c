// 10069c48 FUN_10069c48 [Global]
// programa: RWDL6D21.DLL

void FUN_10069c48(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  
  DAT_1007fc50 = param_2;
  DAT_1007fc4c = param_4 - param_2;
  do {
    while (0x10 < (int)DAT_1007fc50) {
      uVar2 = DAT_1007fc50 >> 4;
      do {
        bVar1 = (char)uVar2 - 1;
        uVar2 = (uint)bVar1;
      } while (bVar1 != 0);
      for (uVar2 = DAT_1007fc50 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *param_1 = 0;
        param_1 = param_1 + 1;
      }
      param_1 = (undefined4 *)((int)param_1 + DAT_1007fc4c);
      param_3 = param_3 + -1;
      if (param_3 == 0) {
        return;
      }
    }
    uVar2 = DAT_1007fc50 >> 1;
    do {
      *(undefined2 *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 2);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    param_1 = (undefined4 *)((int)param_1 + DAT_1007fc4c);
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}


