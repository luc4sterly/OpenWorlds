// 0043dd00 FUN_0043dd00 [Global]
// program: gamma.dll

void __fastcall FUN_0043dd00(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = *(int **)(*param_1 + 0x34);
  uVar2 = (**(code **)(*piVar1 + 0x7c))(piVar1,*(undefined4 *)(*param_1 + 0x38));
  iVar3 = (**(code **)(**(int **)(*param_1 + 0x34) + 0x84))
                    (*(int **)(*param_1 + 0x34),uVar2,s_receiveEvent_0047769c,&DAT_00477694);
  if (iVar3 == 0) {
    (**(code **)(**(int **)(*param_1 + 0x34) + 0x44))(*(int **)(*param_1 + 0x34));
  }
  else {
    FUN_00412800(*(int **)(*param_1 + 0x34),*(undefined4 *)(*param_1 + 0x38),iVar3);
  }
  return;
}


