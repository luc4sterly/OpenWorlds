// 0044c240 FUN_0044c240 [Global]
// programa: gamma.dll

char * __cdecl
FUN_0044c240(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6)

{
  ulonglong uVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint unaff_EDI;
  int local_30;
  char local_28;
  
  local_28 = param_3._1_1_;
  local_30 = param_6;
  bVar2 = false;
  pcVar3 = (char *)(param_2 + -1);
  *pcVar3 = '\0';
  iVar6 = 0;
  if (((param_1 == 0) && (param_6 == 0)) && ((param_3._3_1_ == '\0' || (param_4._1_1_ != 'o')))) {
    return pcVar3;
  }
  switch(param_4._1_1_) {
  case 'X':
  case 'x':
    unaff_EDI = 0x10;
    break;
  default:
    goto switchD_0044c2bd_caseD_59;
  case 'd':
  case 'i':
    unaff_EDI = 10;
    if ((int)param_1 < 0) {
      param_1 = -param_1;
      bVar2 = true;
    }
    goto switchD_0044c2bd_caseD_59;
  case 'o':
    unaff_EDI = 8;
    break;
  case 'u':
    unaff_EDI = 10;
  }
  local_28 = '\0';
switchD_0044c2bd_caseD_59:
  do {
    iVar7 = iVar6;
    pcVar4 = pcVar3;
    uVar1 = (ulonglong)param_1;
    param_1 = param_1 / unaff_EDI;
    cVar5 = (char)(uVar1 % (ulonglong)unaff_EDI);
    if ((int)(uVar1 % (ulonglong)unaff_EDI) < 10) {
      cVar5 = cVar5 + '0';
    }
    else if (param_4._1_1_ == 'x') {
      cVar5 = cVar5 + 'W';
    }
    else {
      cVar5 = cVar5 + '7';
    }
    pcVar3 = pcVar4 + -1;
    *pcVar3 = cVar5;
    iVar6 = iVar7 + 1;
  } while (param_1 != 0);
  if (((unaff_EDI == 8) && (param_3._3_1_ != '\0')) && (*pcVar3 != '0')) {
    pcVar3 = pcVar4 + -2;
    *pcVar3 = '0';
    iVar6 = iVar7 + 2;
  }
  if ((char)param_3 == '\x02') {
    local_30 = param_5;
    if ((bVar2) || (local_28 != '\0')) {
      local_30 = param_5 + -1;
    }
    if ((unaff_EDI == 0x10) && (param_3._3_1_ != '\0')) {
      local_30 = local_30 + -2;
    }
  }
  if (0x1fd < (param_2 - (int)pcVar3) + local_30) {
    return (char *)0x0;
  }
  for (; iVar6 < local_30; iVar6 = iVar6 + 1) {
    pcVar3 = pcVar3 + -1;
    *pcVar3 = '0';
  }
  if ((unaff_EDI == 0x10) && (param_3._3_1_ != '\0')) {
    pcVar3[-1] = param_4._1_1_;
    pcVar3 = pcVar3 + -2;
    *pcVar3 = '0';
  }
  if (bVar2) {
    pcVar3 = pcVar3 + -1;
    *pcVar3 = '-';
  }
  else if (local_28 == '\x01') {
    pcVar3 = pcVar3 + -1;
    *pcVar3 = '+';
  }
  else if (local_28 == '\x02') {
    pcVar3 = pcVar3 + -1;
    *pcVar3 = ' ';
  }
  return pcVar3;
}


