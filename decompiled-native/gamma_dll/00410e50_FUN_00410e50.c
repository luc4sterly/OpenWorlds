// 00410e50 FUN_00410e50 [Global]
// program: gamma.dll

void __thiscall FUN_00410e50(void *param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puStack_60;
  int *piStack_5c;
  undefined1 uStack_55;
  
  FUN_00411b30((void *)((int)param_1 + 0x1c),param_2);
  FUN_00410f00(param_1,&puStack_60);
  uStack_55 = DAT_00489370;
  iVar2 = FUN_00411e00((int *)&puStack_60);
  *(int *)((int)param_1 + 0x2c) = iVar2;
  if ((piStack_5c != (int *)0x0) && (*piStack_5c = *piStack_5c + -1, *piStack_5c == 0)) {
    if (puStack_60 != (undefined4 *)0x0) {
      FUN_00404e60((int)puStack_60);
      FUN_0044e100(puStack_60);
    }
    FUN_0044e100(piStack_5c);
  }
  uVar1 = (**(code **)(**(int **)((int)param_1 + 0x2c) + 0x14))();
  *(undefined1 *)((int)param_1 + 0x41) = uVar1;
  return;
}


