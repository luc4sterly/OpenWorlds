// 00403c2b FUN_00403c2b [Global]
// program: sfmain.exe

void __fastcall FUN_00403c2b(undefined4 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  short in_AX;
  undefined2 *unaff_EBX;
  int local_14;
  
  local_14 = 0xd;
  if ((in_AX < 0) || (3 < in_AX)) {
    FUN_0042b978();
  }
  switch(in_AX) {
  case 0:
    while( true ) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *unaff_EBX = uVar1;
      unaff_EBX = unaff_EBX + 1;
      local_14 = local_14 + -1;
      if (local_14 == 0) break;
switchD_00403c6b_caseD_2:
      *unaff_EBX = 0;
      unaff_EBX = unaff_EBX + 1;
switchD_00403c6b_caseD_1:
      *unaff_EBX = 0;
      unaff_EBX = unaff_EBX + 1;
    }
    break;
  case 1:
    goto switchD_00403c6b_caseD_1;
  case 2:
    goto switchD_00403c6b_caseD_2;
  case 3:
    *unaff_EBX = 0;
    unaff_EBX = unaff_EBX + 1;
    goto switchD_00403c6b_caseD_2;
  }
  while (in_AX = in_AX + 1, in_AX < 4) {
    *unaff_EBX = 0;
    unaff_EBX = unaff_EBX + 1;
  }
  return;
}


