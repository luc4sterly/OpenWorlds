// 0044ec50 FUN_0044ec50 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_0044ec50(int *param_1)

{
  undefined2 *puVar1;
  short sVar2;
  undefined4 uVar3;
  
  sVar2 = (**(code **)(*param_1 + 0x20))();
  if (sVar2 == -1) {
    uVar3 = 0xffffffff;
  }
  else {
    puVar1 = (undefined2 *)param_1[2];
    param_1[2] = param_1[2] + 2;
    uVar3 = CONCAT22((short)((uint)puVar1 >> 0x10),*puVar1);
  }
  return uVar3;
}


