// 00432842 FUN_00432842 [Global]
// programa: sfmain.exe

void __fastcall FUN_00432842(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined1 *in_EAX;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int unaff_EBX;
  int iVar5;
  
  if (param_2 != unaff_EBX) {
    cVar1 = in_EAX[1];
    puVar4 = in_EAX + unaff_EBX;
    puVar2 = in_EAX + param_2;
    do {
      iVar5 = unaff_EBX;
      puVar2 = puVar2 + -1;
      puVar4 = puVar4 + -1;
      *puVar4 = *puVar2;
      unaff_EBX = iVar5 + -1;
    } while (puVar2 != in_EAX);
    iVar3 = CONCAT31((uint3)((uint)puVar2 >> 8) ^ (uint3)((uint)in_EAX >> 8),*in_EAX);
    if (iVar3 == 0x2e) {
      in_EAX[iVar5 + -2] = 0x30;
    }
    else if (((iVar3 == 0x2b) || (iVar3 == 0x2d)) && (cVar1 == '.')) {
      in_EAX[iVar5 + -1] = 0x30;
      in_EAX[iVar5 + -2] = *in_EAX;
    }
    FUN_00408098(in_EAX,0x20);
  }
  return;
}


