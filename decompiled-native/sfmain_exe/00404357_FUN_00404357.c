// 00404357 FUN_00404357 [Global]
// programa: sfmain.exe

/* WARNING: Removing unreachable block (ram,0x00404386) */

void __fastcall FUN_00404357(undefined4 param_1,short *param_2)

{
  short sVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined1 auStack_58 [4];
  undefined2 local_54 [10];
  undefined2 auStack_40 [10];
  undefined4 local_2c;
  int local_18;
  
  if (*in_EAX == 0) {
    iVar2 = 8;
    while (iVar2 = iVar2 + -1, iVar2 != -1) {
      *param_2 = 0;
      param_2 = param_2 + 1;
    }
  }
  else {
    auStack_58 = (undefined1  [4])0x4043a4;
    uVar6 = FUN_00407eb1(param_1,*in_EAX);
    if (((short)uVar6 < 0) || (0x1f < (short)uVar6)) {
      auStack_58 = (undefined1  [4])0x4043c7;
      FUN_0042b978();
    }
    iVar2 = 0;
    do {
      iVar4 = *in_EAX;
      iVar3 = iVar2 + 2;
      in_EAX = in_EAX + 1;
      *(short *)((int)auStack_40 + iVar2) = (short)((uint)(iVar4 << ((byte)uVar6 & 0x1f)) >> 0x10);
      iVar2 = iVar3;
    } while (iVar3 != 0x12);
    iVar2 = 2;
    do {
      iVar4 = iVar2 + 2;
      *(undefined2 *)((int)local_54 + iVar2) = *(undefined2 *)((int)auStack_40 + iVar2);
      iVar2 = iVar4;
    } while (iVar4 != 0x10);
    iVar2 = 0;
    do {
      iVar4 = iVar2 + 2;
      *(undefined2 *)((int)&local_2c + iVar2) = *(undefined2 *)((int)auStack_40 + iVar2);
      iVar2 = iVar4;
    } while (iVar4 != 0x12);
    iVar2 = 1;
    local_18 = 1;
    for (iVar4 = 7; -1 < iVar4; iVar4 = iVar4 + -1) {
      sVar1 = local_2c._2_2_;
      if (local_2c._2_2_ < 0) {
        if (local_2c._2_2_ == -0x8000) {
          sVar1 = 0x7fff;
        }
        else {
          sVar1 = -local_2c._2_2_;
        }
      }
      if ((short)local_2c < sVar1) {
        for (; local_18 < 9; local_18 = local_18 + 1) {
          *param_2 = 0;
          param_2 = param_2 + 1;
        }
        return;
      }
      auStack_58 = (undefined1  [4])0x40447e;
      iVar2 = FUN_0040802d(iVar2,(short)local_2c);
      *param_2 = (short)iVar2;
      if ((short)iVar2 < 0) {
        auStack_58 = (undefined1  [4])0x40449c;
        FUN_0042b978();
      }
      if (0 < local_2c._2_2_) {
        *param_2 = -*param_2;
      }
      if (*param_2 == -0x8000) {
        auStack_58 = (undefined1  [4])0x4044c7;
        FUN_0042b978();
      }
      if (iVar4 == 0) {
        return;
      }
      iVar2 = (int)(short)local_2c +
              (int)(short)((int)*param_2 * (int)local_2c._2_2_ + 0x4000 >> 0xf);
      if (0xffff < iVar2 + 0x8000U) {
        if (iVar2 < 1) {
          iVar2 = -0x8000;
        }
        else {
          iVar2 = 0x7fff;
        }
      }
      local_2c._0_2_ = (short)iVar2;
      iVar2 = iVar4 * 2;
      for (iVar3 = 2; iVar3 <= iVar2; iVar3 = iVar3 + 2) {
        iVar5 = (*(int *)((int)&local_2c + iVar3) >> 0x10) +
                (int)(short)((int)*param_2 * (*(int *)((int)local_54 + iVar3 + -2) >> 0x10) + 0x4000
                            >> 0xf);
        if (0xffff < iVar5 + 0x8000U) {
          if (iVar5 < 1) {
            iVar5 = -0x8000;
          }
          else {
            iVar5 = 0x7fff;
          }
        }
        *(short *)((int)&local_2c + iVar3) = (short)iVar5;
        iVar5 = (int)(short)((int)*param_2 * (*(int *)((int)&local_2c + iVar3) >> 0x10) + 0x4000 >>
                            0xf) + (*(int *)((int)local_54 + iVar3 + -2) >> 0x10);
        if (0xffff < iVar5 + 0x8000U) {
          if (iVar5 < 1) {
            iVar5 = -0x8000;
          }
          else {
            iVar5 = 0x7fff;
          }
        }
        *(short *)((int)local_54 + iVar3) = (short)iVar5;
      }
      local_18 = local_18 + 1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


