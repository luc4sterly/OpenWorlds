// 00453f20 FUN_00453f20 [Global]
// programa: gamma.dll

uint __cdecl
FUN_00453f20(uint param_1,int param_2,undefined *param_3,undefined4 param_4,int *param_5,
            undefined4 *param_6,undefined4 *param_7)

{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_14;
  
  uVar3 = 1;
  iVar5 = 0;
  uVar4 = 0;
  local_14 = 0;
  *param_7 = 0;
  *param_6 = *param_7;
  if (((((int)param_1 < 0) || (param_1 == 1)) || (0x24 < (int)param_1)) || (param_2 < 1)) {
    uVar3 = 0x40;
  }
  else {
    iVar5 = 1;
    unaff_EBX = (*(code *)param_3)(param_4,0,0);
  }
  if (param_1 != 0) {
    local_14 = (uint)(0xffffffff / (ulonglong)param_1);
  }
switchD_00453fae_caseD_3:
  if (((param_2 < iVar5) || (unaff_EBX == 0xffffffff)) || ((uVar3 & 0x60) != 0)) {
    if ((uVar3 & 0x34) == 0) {
      uVar4 = 0;
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 + -1;
    }
    *param_5 = iVar5;
    (*(code *)param_3)(param_4,unaff_EBX,1);
    return uVar4;
  }
  switch(uVar3) {
  case 1:
    if (((&DAT_00482718)[unaff_EBX & 0xff] & 6) == 0) {
      if (unaff_EBX == 0x2b) {
        iVar5 = iVar5 + 1;
        unaff_EBX = (*(code *)param_3)(param_4,0,0);
      }
      else if (unaff_EBX == 0x2d) {
        iVar5 = iVar5 + 1;
        unaff_EBX = (*(code *)param_3)(param_4,0,0);
        *param_6 = 1;
      }
      uVar3 = 2;
      goto switchD_00453fae_caseD_3;
    }
    break;
  case 2:
    if (((param_1 != 0) && (param_1 != 0x10)) || (unaff_EBX != 0x30)) {
      uVar3 = 8;
      goto switchD_00453fae_caseD_3;
    }
    uVar3 = 4;
    break;
  default:
    goto switchD_00453fae_caseD_3;
  case 4:
    if ((unaff_EBX != 0x58) && (unaff_EBX != 0x78)) {
      if (param_1 == 0) {
        param_1 = 8;
      }
      uVar3 = 0x10;
      goto switchD_00453fae_caseD_3;
    }
    param_1 = 0x10;
    uVar3 = 8;
    break;
  case 8:
  case 0x10:
    if (param_1 == 0) {
      param_1 = 10;
    }
    if (local_14 == 0) {
      local_14 = (uint)(0xffffffff / (ulonglong)param_1);
    }
    uVar1 = unaff_EBX & 0xff;
    if (((&DAT_00482718)[uVar1] & 0x10) == 0) {
      if (((&DAT_00482718)[uVar1] & 0xc0) != 0) {
        if (unaff_EBX == 0xffffffff) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = (uint)(byte)(&DAT_00482918)[uVar1];
        }
        if ((int)(uVar2 - 0x37) < (int)param_1) {
          if (unaff_EBX == 0xffffffff) {
            uVar1 = 0xffffffff;
          }
          else {
            uVar1 = (uint)(byte)(&DAT_00482918)[uVar1];
          }
          uVar1 = uVar1 - 0x37;
          goto LAB_0045411b;
        }
      }
      if (uVar3 == 0x10) {
        uVar3 = 0x20;
      }
      else {
        uVar3 = 0x40;
      }
      goto switchD_00453fae_caseD_3;
    }
    uVar1 = unaff_EBX - 0x30;
    if ((int)param_1 <= (int)uVar1) {
      if (uVar3 == 0x10) {
        uVar3 = 0x20;
      }
      else {
        uVar3 = 0x40;
      }
      goto switchD_00453fae_caseD_3;
    }
LAB_0045411b:
    if (local_14 < uVar4) {
      *param_7 = 1;
    }
    if (-(uVar4 * param_1) - 1 < uVar1) {
      *param_7 = 1;
    }
    uVar4 = uVar4 * param_1 + uVar1;
    uVar3 = 0x10;
  }
  iVar5 = iVar5 + 1;
  unaff_EBX = (*(code *)param_3)(param_4,0,0);
  goto switchD_00453fae_caseD_3;
}


