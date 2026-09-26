// 0042d745 FUN_0042d745 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0042d745(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  int *piVar3;
  
  piVar1 = DAT_0043e524;
  piVar3 = (int *)0x0;
  while ((piVar2 = piVar1, piVar2 != (int *)0x0 && (piVar2 <= in_EAX))) {
    piVar3 = piVar2;
    piVar1 = (int *)piVar2[2];
  }
  in_EAX[1] = (int)piVar3;
  in_EAX[2] = (int)piVar2;
  piVar1 = in_EAX;
  if (piVar3 != (int *)0x0) {
    piVar3[2] = (int)in_EAX;
    piVar1 = DAT_0043e524;
  }
  DAT_0043e524 = piVar1;
  if (piVar2 != (int *)0x0) {
    piVar2[1] = (int)in_EAX;
  }
  piVar1 = in_EAX + 8;
  piVar3 = in_EAX + 0xb;
  in_EAX[8] = 0;
  in_EAX[4] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[9] = (int)piVar1;
  in_EAX[10] = (int)piVar1;
  in_EAX[3] = (int)piVar1;
  *piVar3 = *in_EAX + -0x2c;
  *(undefined4 *)((int)piVar3 + *in_EAX + -0x2c) = 0xffffffff;
  return CONCAT44(param_2,piVar3);
}


