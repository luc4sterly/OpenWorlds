// 00403d7d FUN_00403d7d [Global]
// program: sfmain.exe

void __fastcall FUN_00403d7d(undefined4 param_1,short *param_2)

{
  short sVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *unaff_EBX;
  int local_24;
  short local_20;
  undefined2 uStack_1e;
  short local_18;
  short local_14;
  
  local_20 = (short)*(undefined4 *)(in_EAX + 0x234);
  uStack_1e = (undefined2)((uint)*(undefined4 *)(in_EAX + 0x234) >> 0x10);
  local_14 = *(short *)(in_EAX + 0x238);
  local_24 = 0xa0;
  local_18 = *(short *)(in_EAX + 0x230);
  while (local_24 = local_24 + -1, local_24 != -1) {
    sVar1 = (short)(((int)*param_2 >> 3) << 2);
    param_2 = param_2 + 1;
    if (sVar1 < -0x4000) {
      FUN_0042b978();
    }
    if (0x3ffc < sVar1) {
      FUN_0042b978();
    }
    if ((short)(sVar1 - local_18) == -0x8000) {
      FUN_0042b978();
    }
    iVar4 = CONCAT22(uStack_1e,local_20) >> 0xf;
    iVar2 = (short)(sVar1 - local_18) * 0x8000 +
            (int)(short)((short)(local_20 - (short)(iVar4 << 0xf)) * 0x7fdf + 0x4000 >> 0xf);
    iVar4 = (short)iVar4 * 0x7fdf;
    uVar3 = iVar4 + iVar2;
    if (iVar4 < 0) {
      if (iVar2 < 0) {
        uVar3 = -(iVar2 + 1) - (iVar4 + 1);
        if (uVar3 < 0x7fffffff) {
          uVar3 = 0xfffffffe - uVar3;
        }
        else {
          uVar3 = 0x80000000;
        }
      }
    }
    else if ((0 < iVar2) && (0x7ffffffe < uVar3)) {
      uVar3 = 0x7fffffff;
    }
    local_20 = (short)uVar3;
    uStack_1e = (undefined2)(uVar3 >> 0x10);
    uVar5 = uVar3 + 0x4000;
    if ((-1 < (int)uVar3) && (0x7ffffffe < uVar5)) {
      uVar5 = 0x7fffffff;
    }
    iVar2 = (int)local_14;
    local_14 = (short)((int)uVar5 >> 0xf);
    iVar2 = (int)local_14 + (int)(short)(iVar2 * -0x6e14 + 0x4000 >> 0xf);
    if (0xffff < iVar2 + 0x8000U) {
      if (iVar2 < 1) {
        iVar2 = -0x8000;
      }
      else {
        iVar2 = 0x7fff;
      }
    }
    *unaff_EBX = (short)iVar2;
    unaff_EBX = unaff_EBX + 1;
    local_18 = sVar1;
  }
  *(short *)(in_EAX + 0x230) = local_18;
  *(uint *)(in_EAX + 0x234) = CONCAT22(uStack_1e,local_20);
  *(int *)(in_EAX + 0x238) = (int)local_14;
  return;
}


