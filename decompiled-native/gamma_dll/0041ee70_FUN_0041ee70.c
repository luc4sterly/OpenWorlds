// 0041ee70 FUN_0041ee70 [Global]
// program: gamma.dll

void __cdecl FUN_0041ee70(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined1 local_18 [8];
  
  iVar1 = FUN_00419510(param_1);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = FUN_00419830(iVar1);
  if (iVar1 != 0) {
    uVar2 = FUN_004195b0(param_1);
    if ((uVar2 & 0x40000000) == 0) {
      if ((uVar2 & 0x20000000) == 0) {
        return;
      }
      DAT_0049cfc0 = param_2;
      DAT_0049cfc4 = (undefined1 *)0x0;
      DAT_0049cfc8 = param_1;
      iVar6 = FUN_00419480(param_1);
      iVar7 = 1;
      if (0 < iVar6) {
        do {
          iVar3 = FUN_004189c0(param_1,iVar7);
          if (iVar3 != 0) {
            FUN_0041e780(iVar3,iVar1);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 <= iVar6);
      }
    }
    else {
      iVar6 = 0;
      iVar7 = 0x18;
      do {
        cVar5 = ((byte)((int)uVar2 >> ((byte)iVar7 & 0x1f)) & 0x3f) + 0x20;
        if (cVar5 != ' ') {
          if (cVar5 == -1) {
            uVar4 = 0xff;
          }
          else {
            uVar4 = (&DAT_00482818)[cVar5];
          }
          local_18[iVar6] = uVar4;
          iVar6 = iVar6 + 1;
        }
        iVar7 = iVar7 + -6;
      } while (-1 < iVar7);
      local_18[iVar6] = 0;
      DAT_0049cfc4 = local_18;
      DAT_0049cfc8 = param_1;
      DAT_0049cfc0 = param_2;
      iVar6 = FUN_00419480(param_1);
      iVar7 = 1;
      if (0 < iVar6) {
        do {
          iVar3 = FUN_004189c0(param_1,iVar7);
          if (iVar3 != 0) {
            FUN_0041e780(iVar3,iVar1);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 <= iVar6);
      }
      DAT_0049cfc4 = (undefined1 *)0x0;
    }
    DAT_0049cfc8 = 0;
    DAT_0049cfc0 = 0;
    return;
  }
  return;
}


