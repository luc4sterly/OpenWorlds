// 0044f340 FUN_0044f340 [Global]
// program: gamma.dll

void __thiscall FUN_0044f340(void *param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int aiStack_60 [2];
  undefined1 uStack_55;
  
  FUN_00411b30((void *)((int)param_1 + 0x1c),param_2);
  FUN_0044f3d0(param_1,aiStack_60);
  uStack_55 = DAT_0049e41b;
  iVar2 = FUN_004501b0(aiStack_60);
  *(int *)((int)param_1 + 0x2c) = iVar2;
  FUN_00404dc0(aiStack_60);
  uVar1 = (**(code **)(**(int **)((int)param_1 + 0x2c) + 0x14))();
  *(undefined1 *)((int)param_1 + 0x51) = uVar1;
  return;
}


