// 004326a6 FUN_004326a6 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004326a6(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int extraout_ECX;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  (*(code *)PTR_FUN_0043e818)(param_2,param_1);
  puVar1 = _DAT_004e592c;
  puVar3 = (undefined4 *)&DAT_004e592c;
  do {
    puVar2 = puVar1;
    if (puVar2 == (undefined4 *)0x0) {
LAB_004326e6:
      (*(code *)PTR_FUN_0043e81c)();
      return;
    }
    if (extraout_ECX == puVar2[1]) {
      if (puVar2[3] != 0) {
        FUN_0042b9b8();
        puVar2 = extraout_EDX;
      }
      *puVar3 = *puVar2;
      FUN_0042b9b8();
      goto LAB_004326e6;
    }
    puVar1 = (undefined4 *)*puVar2;
    puVar3 = puVar2;
  } while( true );
}


