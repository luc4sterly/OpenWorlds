// 0040688f FUN_0040688f [Global]
// programa: gdkup.exe

void __fastcall FUN_0040688f(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int extraout_ECX;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  (*(code *)PTR_FUN_00408b64)(param_2,param_1);
  puVar1 = DAT_0040b5dc;
  puVar3 = &DAT_0040b5dc;
  do {
    puVar2 = puVar1;
    if (puVar2 == (undefined4 *)0x0) {
LAB_004068cf:
      (*(code *)PTR_FUN_00408b68)();
      return;
    }
    if (extraout_ECX == puVar2[1]) {
      if (puVar2[3] != 0) {
        FUN_00403235();
        puVar2 = extraout_EDX;
      }
      *puVar3 = *puVar2;
      FUN_00403235();
      goto LAB_004068cf;
    }
    puVar1 = (undefined4 *)*puVar2;
    puVar3 = puVar2;
  } while( true );
}


