// 0042b8eb FUN_0042b8eb [Global]
// program: sfmain.exe

void __fastcall FUN_0042b8eb(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  uint uVar1;
  uint unaff_EBX;
  undefined4 *puVar2;
  undefined2 *puVar3;
  
  if (param_2 != in_EAX) {
    if ((param_2 < in_EAX) && (in_EAX < (undefined4 *)((int)param_2 + unaff_EBX))) {
      uVar1 = unaff_EBX >> 1;
      puVar2 = (undefined4 *)((int)param_2 + unaff_EBX);
      puVar3 = (undefined2 *)((int)in_EAX + unaff_EBX);
      while( true ) {
        if (uVar1 == 0) break;
        uVar1 = uVar1 - 1;
        puVar3[-1] = *(undefined2 *)((int)puVar2 - 2U);
        puVar2 = (undefined4 *)((int)puVar2 - 2U);
        puVar3 = puVar3 + -1;
      }
      uVar1 = (uint)((unaff_EBX & 1) != 0);
      while( true ) {
        puVar3 = (undefined2 *)((int)puVar3 + -1);
        puVar2 = (undefined4 *)((int)puVar2 - 1);
        if (uVar1 == 0) break;
        uVar1 = uVar1 - 1;
        *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      }
      return;
    }
    for (uVar1 = unaff_EBX >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *in_EAX = *param_2;
      param_2 = param_2 + 1;
      in_EAX = in_EAX + 1;
    }
    for (uVar1 = unaff_EBX & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)in_EAX = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      in_EAX = (undefined4 *)((int)in_EAX + 1);
    }
  }
  return;
}


