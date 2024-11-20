﻿// ------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version: 17.0.0.0
//  
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
// ------------------------------------------------------------------------------
namespace Microsoft.UI.Xaml.Markup.Compiler.CodeGen
{
    using System;
    
    /// <summary>
    /// Class to produce the template output
    /// </summary>
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.VisualStudio.TextTemplating", "17.0.0.0")]
    internal partial class CXTemplatedMetadataDelegates : CppCX_CodeGenerator<TypeInfoDefinition>
    {
        /// <summary>
        /// Create the template output
        /// </summary>
        public override string TransformText()
        {
            this.Write("template<typename T>\r\n::Platform::Object^ ActivateType()\r\n{\r\n    return ref new T" +
                    ";\r\n}\r\n\r\n");
 if (!ProjectInfo.EnableTypeInfoReflection) 
 { 
            this.Write(@"template<typename TInstance, typename TItem>
void CollectionAdd(::Platform::Object^ instance, ::Platform::Object^ item)
{
    safe_cast<TInstance^>(instance)->Append((TItem)item);
}

template<typename TInstance, typename TKey, typename TItem>
void DictionaryAdd(::Platform::Object^ instance, ::Platform::Object^ key, ::Platform::Object^ item)
{
    safe_cast<TInstance^>(instance)->Insert((TKey)key, (TItem)item);
}

template<typename T>
::Platform::Object^ FromStringConverter(::XamlTypeInfo::InfoProvider::XamlUserType^ userType, ::Platform::String^ input)
{
    return ref new ::Platform::Box<T>((T)userType->CreateEnumUIntFromString(input));
}
");
  foreach(String name in Model.AttachableMemberGetterUniqueNames) 
  { 
            this.Write("\r\ntemplate<typename TDeclaringType, typename TargetType>\r\n::Platform::Object^ Get" +
                    "AttachableMember_");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write("(::Platform::Object^ instance)\r\n{\r\n    return TDeclaringType::Get");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write("(safe_cast<TargetType^>(instance));\r\n}\r\n");
  } 
  foreach(String name in Model.ValueTypeMemberGetterUniqueNames) 
  { 
            this.Write("\r\ntemplate<typename TDeclaringType, typename TValue>\r\n::Platform::Object^ GetValu" +
                    "eTypeMember_");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write("(::Platform::Object^ instance)\r\n{\r\n    return ref new ::Platform::Box<TValue>(saf" +
                    "e_cast<TDeclaringType^>(instance)->");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write(");\r\n}\r\n");
  } 
  foreach(String name in Model.ReferenceTypeMemberGetterUniqueNames) 
  { 
            this.Write("\r\ntemplate<typename TDeclaringType>\r\n::Platform::Object^ GetReferenceTypeMember_");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write("(::Platform::Object^ instance)\r\n{\r\n    return safe_cast<TDeclaringType^>(instance" +
                    ")->");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write(";\r\n}\r\n");
  } 
  foreach(String name in Model.AttachableMemberSetterUniqueNames) 
  { 
            this.Write("\r\ntemplate<typename TDeclaringType, typename TTargetType, typename TValue>\r\nvoid " +
                    "SetAttachableMember_");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write("(::Platform::Object^ instance, ::Platform::Object^ value)\r\n{\r\n    TDeclaringType:" +
                    ":Set");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write("(safe_cast<TTargetType^>(instance), (TValue)value);\r\n}\r\n");
  } 
  foreach(String name in Model.EnumTypeMemberSetterUniqueNames) 
  { 
            this.Write("\r\ntemplate<typename TDeclaringType, typename TValue>\r\nvoid SetEnumMember_");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write("(::Platform::Object^ instance, ::Platform::Object^ value)\r\n{\r\n    safe_cast<TDecl" +
                    "aringType^>(instance)->");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write(" = safe_cast<::Platform::IBox<TValue>^>(value)->Value;\r\n}\r\n");
  } 
  foreach(String name in Model.ValueTypeMemberSetterUniqueNames) 
  { 
            this.Write("\r\ntemplate<typename TDeclaringType, typename TValue>\r\nvoid SetValueTypeMember_");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write("(::Platform::Object^ instance, ::Platform::Object^ value)\r\n{\r\n    safe_cast<TDecl" +
                    "aringType^>(instance)->");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write(" = safe_cast<::Platform::IBox<TValue>^>(value)->Value;\r\n}\r\n");
  } 
  foreach(String name in Model.ReferenceTypeMemberSetterUniqueNames) 
  { 
            this.Write("\r\ntemplate<typename TDeclaringType, typename TValue>\r\nvoid SetReferenceTypeMember" +
                    "_");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write("(::Platform::Object^ instance, ::Platform::Object^ value)\r\n{\r\n    safe_cast<TDecl" +
                    "aringType^>(instance)->");
            this.Write(this.ToStringHelper.ToStringWithCulture(name));
            this.Write(" = safe_cast<TValue^>(value);\r\n}\r\n");
  } 
 } // End of type info reflection check 
            return this.GenerationEnvironment.ToString();
        }
    }
}