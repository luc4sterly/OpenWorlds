// 00459037 caseD_0 [switchD_00459030]
// program: gamma.dll

int switchD_00459030::caseD_0(void)

{
  char cVar1;
  int *unaff_EBX;
  
  cVar1 = *(char *)*unaff_EBX;
  if (cVar1 == '\0') {
    unaff_EBX[1] = 1;
    return -1;
  }
  *unaff_EBX = *unaff_EBX + 1;
  return (int)cVar1;
}


