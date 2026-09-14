// 00450f30 FUN_00450f30 [Global]
// programa: gamma.dll

int __cdecl FUN_00450f30(int *param_1,uint param_2,undefined2 param_3)

{
  int *unaff_ESI;
  int *piVar1;
  
  if ((param_2 & 0xffffff00) == 0x80000000) {
    switch(param_2 & 0xff) {
    case 3:
      unaff_ESI = param_1;
      break;
    default:
      FUN_00458ca0();
      break;
    case 6:
      unaff_ESI = param_1 + 1;
      break;
    case 7:
      unaff_ESI = param_1 + 2;
    }
    switch(param_3) {
    case 2:
      return (int)(short)*unaff_ESI;
    default:
      return (int)(char)*unaff_ESI;
    case 4:
      return *unaff_ESI;
    }
  }
  piVar1 = (int *)(param_1[3] + param_2);
  switch(param_3) {
  case 2:
    return (int)(short)*piVar1;
  default:
    return (int)(char)*piVar1;
  case 4:
    return *piVar1;
  }
}


