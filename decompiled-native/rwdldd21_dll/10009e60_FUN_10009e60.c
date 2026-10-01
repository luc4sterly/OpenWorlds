// 10009e60 FUN_10009e60 [Global]
// program: RWDLDD21.DLL

/* WARNING: Removing unreachable block (ram,0x10009f74) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10009e60(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4)

{
  DWORD DVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined1 local_70 [112];
  
  DVar1 = GetVersion();
  if (DVar1 < 0x80000000) {
    if ((DVar1 & 0xff) < 4) {
      DAT_10036094 = 0;
    }
    else {
      DAT_10036094 = 1;
    }
  }
  else if (((DVar1 & 0xff) == 3) && ((DVar1 >> 8 & 0xff) < 0x5f)) {
    DAT_10036094 = 0;
  }
  else {
    DAT_10036094 = 2;
  }
  if (DAT_10036094 == 0) {
    return 0;
  }
  if (0 < param_3) {
    FUN_10009620(param_3,param_4);
  }
  if (((*(uint *)(DAT_10036064 + 0x10) & 2) == 0) && (DAT_100360b0 == 0)) {
    return 0;
  }
  if ((*(uint *)(DAT_10036064 + 0x10 + DAT_10036060 * 0x28) & 2) != 0) {
    piVar5 = (int *)0x0;
    piVar4 = *(int **)(DAT_10036064 + DAT_10036060 * 0x28 + 0x14);
    iVar2 = DirectDrawCreate(piVar4,local_70);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)&stack0xffffff88;
      for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      (**(code **)(*piVar5 + 0x30))(piVar5,&stack0xffffff88);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 8))(piVar4);
      }
    }
  }
  if (DAT_100360a0 == 0) {
    _DAT_100360a4 = *(undefined4 *)(DAT_10036064 + 8 + DAT_10036060 * 0x28);
    _DAT_10036098 = 4;
  }
  else {
    if ((DAT_100360a0 != 0x10) && (DAT_100360a0 != 0x20)) {
      return 0;
    }
    DAT_100360a8 = DAT_100360a0;
  }
  return 1;
}


