// 10008fc0 FUN_10008fc0 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10008fc0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x2c) + 0x34);
  DAT_1003a024 = iVar1 + 0xc;
  *(undefined4 *)(iVar1 + 0xac) = param_2;
  if (DAT_10036044 != (int *)0x0) {
    (**(code **)(*DAT_10036044 + 0x20))(DAT_10036044,0,param_2);
  }
  (*DAT_100360c8)(param_1,param_2);
  if ((*(uint *)(param_1 + 0x228) & 1) == 0) {
    DAT_10042034 = *(undefined4 *)(param_1 + 100);
    DAT_10042038 = *(undefined4 *)(param_1 + 0x68);
  }
  else {
    DAT_10042034 = *(undefined4 *)(param_1 + 0x54);
    DAT_10042038 = *(undefined4 *)(param_1 + 0x58);
  }
  DAT_10036068 = (uint)(*(int *)(param_1 + 0x218) == 1);
  do {
    iVar1 = (**(code **)(*DAT_10036038 + 0x34))(DAT_10036038,2);
    if (iVar1 == -0x7789fe3e) {
      puVar2 = (undefined4 *)&stack0xffffff8c;
      for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0xffffff8c,0,&LAB_10001b40);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      iVar1 = (**(code **)(*DAT_10036038 + 0x34))(DAT_10036038,2);
    }
  } while (iVar1 != 0);
  iVar1 = (**(code **)(**(int **)(DAT_1003a024 + 8) + 0x4c))(*(int **)(DAT_1003a024 + 8));
  if (iVar1 == -0x7789fe3e) {
    puVar2 = (undefined4 *)&stack0xffffff88;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0xffffff88,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    (**(code **)(**(int **)(DAT_1003a024 + 8) + 0x4c))(*(int **)(DAT_1003a024 + 8));
  }
  if ((*(int *)(DAT_1003a024 + 0x78) != 0) &&
     ((DAT_1003608c != 0 || (*(float *)(param_1 + 0x78) != _DAT_10036080)))) {
    _DAT_10036080 = *(float *)(param_1 + 0x78);
    bVar3 = DAT_10036078 != 0;
    _DAT_10036084 = _DAT_10034054 / (_DAT_10036080 - _DAT_1003607c);
    DAT_1003608c = 0;
    **(undefined1 **)(DAT_1003a024 + 0x30) = 8;
    *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
    if (bVar3) {
      *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 2;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x1c;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x22;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = DAT_10036070;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      return;
    }
    *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 0x1c;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  }
  return;
}


