// 004042a8 FUN_004042a8 [Global]
// program: gdkup.exe

void __fastcall FUN_004042a8(undefined4 param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined2 *puVar3;
  uint in_EAX;
  undefined4 uVar4;
  byte bVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 uVar7;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 *puVar8;
  undefined4 extraout_EDX_05;
  int unaff_EBX;
  undefined8 uVar9;
  uint local_24;
  undefined4 local_18;
  undefined4 uVar6;
  
  FUN_00405b02(param_1,param_2);
  uVar7 = extraout_ECX;
  uVar4 = extraout_EDX;
  if (unaff_EBX != 0) {
    FUN_00405b23();
    uVar7 = extraout_ECX_00;
    uVar4 = extraout_EDX_00;
  }
  piVar1 = *(int **)(param_2 + 4);
  uVar9 = FUN_00404214(uVar7,uVar4);
  uVar7 = extraout_ECX_01;
switchD_004043a9_caseD_2:
  while( true ) {
    uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
    local_18 = (undefined4)uVar9;
    if (local_24 == in_EAX) {
      *(uint *)(param_2 + 8) = local_24;
      return;
    }
    if (local_24 < in_EAX) {
      FUN_00405c57();
      uVar7 = extraout_ECX_06;
      uVar4 = extraout_EDX_04;
    }
    FUN_00405b28(uVar7,uVar4);
    uVar9 = FUN_00404214(extraout_ECX_07,local_18);
    puVar8 = (undefined4 *)((ulonglong)uVar9 >> 0x20);
    uVar4 = (undefined4)uVar9;
    *(uint *)(param_2 + 8) = local_24;
    pcVar2 = (code *)*puVar8;
    if (pcVar2 == (code *)0x0) break;
    (**(code **)(*(int *)(&DAT_0040b448 + *piVar1 * 4) + 4))();
    (*pcVar2)();
    uVar9 = CONCAT44(extraout_EDX_05,uVar4);
    uVar7 = extraout_ECX_09;
  }
  puVar3 = (undefined2 *)puVar8[1];
  uVar7 = extraout_ECX_08;
  switch(*puVar3) {
  default:
    FUN_00405c57();
  case 0:
    (**(code **)(*(int *)(&DAT_0040b448 + *piVar1 * 4) + 4))();
    uVar7 = *(undefined4 *)(puVar3 + 3);
    uVar6 = extraout_ECX_02;
    goto LAB_00404300;
  case 2:
  case 3:
  case 4:
    goto switchD_004043a9_caseD_2;
  case 6:
    bVar5 = 0x11;
    break;
  case 7:
    bVar5 = 0x10;
    break;
  case 8:
    bVar5 = 0x10;
    break;
  case 9:
    uVar7 = *(undefined4 *)(param_2 + 8 + *(int *)(puVar3 + 1));
    uVar6 = extraout_ECX_08;
LAB_00404300:
    FUN_00403208(uVar6,uVar7);
    uVar9 = CONCAT44(extraout_EDX_01,uVar4);
    uVar7 = extraout_ECX_03;
    goto switchD_004043a9_caseD_2;
  case 10:
    goto LAB_00404343;
  case 0xb:
LAB_00404343:
    (**(code **)(puVar3 + 3))();
    uVar9 = CONCAT44(extraout_EDX_03,uVar4);
    uVar7 = extraout_ECX_05;
    goto switchD_004043a9_caseD_2;
  }
  FUN_0040425e(bVar5);
  uVar9 = CONCAT44(extraout_EDX_02,uVar4);
  uVar7 = extraout_ECX_04;
  goto switchD_004043a9_caseD_2;
}


