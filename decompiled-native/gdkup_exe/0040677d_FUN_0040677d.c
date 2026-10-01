// 0040677d FUN_0040677d [Global]
// program: gdkup.exe

undefined4 * __fastcall FUN_0040677d(undefined4 param_1,int param_2)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  uint uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  
  if (in_EAX == (undefined4 *)0x0) {
    uVar5 = FUN_004032c3(param_2,param_2);
    puVar1 = (undefined4 *)uVar5;
  }
  else if (param_2 == 0) {
    FUN_00403235();
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = FUN_00406ed7();
    uVar5 = FUN_00406ee0();
    puVar1 = (undefined4 *)uVar5;
    if (puVar1 == (undefined4 *)0x0) {
      uVar5 = FUN_004032c3(extraout_ECX,(int)((ulonglong)uVar5 >> 0x20));
      puVar1 = (undefined4 *)uVar5;
      if (puVar1 == (undefined4 *)0x0) {
        FUN_00406ee0();
      }
      else {
        puVar4 = puVar1;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = *in_EAX;
          in_EAX = in_EAX + 1;
          puVar4 = puVar4 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar4 = *(undefined1 *)in_EAX;
          in_EAX = (undefined4 *)((int)in_EAX + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        FUN_00403235();
      }
    }
  }
  return puVar1;
}


