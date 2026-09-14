// 0044c3f0 FUN_0044c3f0 [Global]
// programa: gamma.dll

char * __cdecl
FUN_0044c3f0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6,
            int param_7)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int local_44;
  char local_3c;
  undefined8 local_28;
  uint local_20;
  uint local_1c;
  
  local_3c = param_4._1_1_;
  local_44 = param_7;
  local_28 = CONCAT44(param_2,param_1);
  bVar1 = false;
  pcVar3 = (char *)(param_3 + -1);
  *pcVar3 = '\0';
  iVar5 = 0;
  if (((param_1 == 0 && param_2 == 0) && (param_7 == 0)) &&
     ((param_4._3_1_ == '\0' || (param_5._1_1_ != 'o')))) {
    return pcVar3;
  }
  switch(param_5._1_1_) {
  case 'X':
  case 'x':
    local_20 = 0x10;
    break;
  default:
    goto switchD_0044c47d_caseD_59;
  case 'd':
  case 'i':
    local_20 = 10;
    local_1c = 0;
    if ((param_2 != 0) && (param_2 < 0)) {
      local_28 = CONCAT44(-(param_2 + (uint)(param_1 != 0)),-param_1);
      bVar1 = true;
    }
    goto switchD_0044c47d_caseD_59;
  case 'o':
    local_20 = 8;
    break;
  case 'u':
    local_20 = 10;
  }
  local_1c = 0;
  local_3c = '\0';
switchD_0044c47d_caseD_59:
  do {
    iVar6 = iVar5;
    pcVar4 = pcVar3;
    uVar8 = FUN_00453d00((uint)local_28,local_28._4_4_,local_20,local_1c);
    uVar9 = FUN_00453bc0((uint)local_28,local_28._4_4_,local_20,local_1c);
    cVar2 = (char)uVar8;
    if ((int)uVar8 < 10) {
      cVar2 = cVar2 + '0';
    }
    else if (param_5._1_1_ == 'x') {
      cVar2 = cVar2 + 'W';
    }
    else {
      cVar2 = cVar2 + '7';
    }
    pcVar3 = pcVar4 + -1;
    *pcVar3 = cVar2;
    iVar5 = iVar6 + 1;
    local_28._4_4_ = (uint)(uVar9 >> 0x20);
    bVar7 = false;
    if (local_28._4_4_ == 0) {
      local_28._0_4_ = (uint)uVar9;
      bVar7 = (uint)local_28 == 0;
    }
    local_28 = uVar9;
  } while (!bVar7);
  if (((local_1c == 0 && local_20 == 8) && (param_4._3_1_ != '\0')) && (*pcVar3 != '0')) {
    pcVar3 = pcVar4 + -2;
    *pcVar3 = '0';
    iVar5 = iVar6 + 2;
  }
  if ((char)param_4 == '\x02') {
    local_44 = param_6;
    if ((bVar1) || (local_3c != '\0')) {
      local_44 = param_6 + -1;
    }
    if ((local_1c == 0 && local_20 == 0x10) && (param_4._3_1_ != '\0')) {
      local_44 = local_44 + -2;
    }
  }
  if ((param_3 - (int)pcVar3) + local_44 < 0x1fe) {
    for (; iVar5 < local_44; iVar5 = iVar5 + 1) {
      pcVar3 = pcVar3 + -1;
      *pcVar3 = '0';
    }
    if ((local_1c == 0 && local_20 == 0x10) && (param_4._3_1_ != '\0')) {
      pcVar3[-1] = param_5._1_1_;
      pcVar3 = pcVar3 + -2;
      *pcVar3 = '0';
    }
    if (bVar1) {
      pcVar3 = pcVar3 + -1;
      *pcVar3 = '-';
    }
    else if (local_3c == '\x01') {
      pcVar3 = pcVar3 + -1;
      *pcVar3 = '+';
    }
    else if (local_3c == '\x02') {
      pcVar3 = pcVar3 + -1;
      *pcVar3 = ' ';
    }
    return pcVar3;
  }
  return (char *)0x0;
}


