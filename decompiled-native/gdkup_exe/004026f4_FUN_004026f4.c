// 004026f4 FUN_004026f4 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_004026f4(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int in_EAX;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int extraout_EDX;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (in_EAX == 0) {
    in_EAX = 1;
  }
LAB_00402702:
  uVar3 = FUN_004032c3(param_1,in_EAX);
  if ((int)uVar3 == 0) {
    iVar2 = (*(code *)PTR_FUN_00408b38)();
    pcVar1 = *(code **)(iVar2 + DAT_0040b440 + 0x1c);
    if (pcVar1 != (code *)0x0) goto code_r0x00402726;
    goto LAB_00402730;
  }
LAB_0040274b:
  return CONCAT44(param_2,(int)uVar3);
code_r0x00402726:
  uVar4 = (*pcVar1)();
  in_EAX = (int)((ulonglong)uVar4 >> 0x20);
  param_1 = extraout_ECX;
  if ((int)uVar4 == 0) {
LAB_00402730:
    iVar2 = (*(code *)PTR_FUN_00408b38)();
    pcVar1 = *(code **)(iVar2 + DAT_0040b440 + 0x18);
    if (pcVar1 == (code *)0x0) goto LAB_0040274b;
    (*pcVar1)();
    param_1 = extraout_ECX_00;
    in_EAX = extraout_EDX;
  }
  goto LAB_00402702;
}


