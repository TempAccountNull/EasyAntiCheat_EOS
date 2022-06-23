int EOS::InitalizeRegistryWow6432Node()
{
  int result;
  _UNICODE_STRING DestinationString; 
  _OBJECT_ATTRIBUTES ObjectAttributes; 
  void *KeyHandle; 

  RtlInitUnicodeString(&DestinationString, L"\\Registry\\Machine\\Software\\Wow6432Node\\EasyAntiCheat_EOS");
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 0x30;
  ObjectAttributes.Attributes = 0x240;
  ObjectAttributes.SecurityDescriptor = 0;
  
  result = ZwOpenKey(&KeyHandle, 0x20019, &ObjectAttributes);
  if ( result >= 0 )
  {
    ZwFlushKey(KeyHandle);
    return ZwClose(KeyHandle);
  }
  return result;
}
