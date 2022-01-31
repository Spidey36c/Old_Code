﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace TBlogServiceClient.TBlogServiceReference {
    using System.Runtime.Serialization;
    using System;
    
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Runtime.Serialization", "4.0.0.0")]
    [System.Runtime.Serialization.DataContractAttribute(Name="Blog", Namespace="http://schemas.datacontract.org/2004/07/TBlogService.Models")]
    [System.SerializableAttribute()]
    public partial class Blog : object, System.Runtime.Serialization.IExtensibleDataObject, System.ComponentModel.INotifyPropertyChanged {
        
        [System.NonSerializedAttribute()]
        private System.Runtime.Serialization.ExtensionDataObject extensionDataField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string EMailField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string SubTitleField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string TitleField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string UserNameField;
        
        [global::System.ComponentModel.BrowsableAttribute(false)]
        public System.Runtime.Serialization.ExtensionDataObject ExtensionData {
            get {
                return this.extensionDataField;
            }
            set {
                this.extensionDataField = value;
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string EMail {
            get {
                return this.EMailField;
            }
            set {
                if ((object.ReferenceEquals(this.EMailField, value) != true)) {
                    this.EMailField = value;
                    this.RaisePropertyChanged("EMail");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string SubTitle {
            get {
                return this.SubTitleField;
            }
            set {
                if ((object.ReferenceEquals(this.SubTitleField, value) != true)) {
                    this.SubTitleField = value;
                    this.RaisePropertyChanged("SubTitle");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string Title {
            get {
                return this.TitleField;
            }
            set {
                if ((object.ReferenceEquals(this.TitleField, value) != true)) {
                    this.TitleField = value;
                    this.RaisePropertyChanged("Title");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string UserName {
            get {
                return this.UserNameField;
            }
            set {
                if ((object.ReferenceEquals(this.UserNameField, value) != true)) {
                    this.UserNameField = value;
                    this.RaisePropertyChanged("UserName");
                }
            }
        }
        
        public event System.ComponentModel.PropertyChangedEventHandler PropertyChanged;
        
        protected void RaisePropertyChanged(string propertyName) {
            System.ComponentModel.PropertyChangedEventHandler propertyChanged = this.PropertyChanged;
            if ((propertyChanged != null)) {
                propertyChanged(this, new System.ComponentModel.PropertyChangedEventArgs(propertyName));
            }
        }
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="TBlogServiceReference.IBlogService")]
    public interface IBlogService {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IBlogService/GetBlogs", ReplyAction="http://tempuri.org/IBlogService/GetBlogsResponse")]
        TBlogServiceClient.TBlogServiceReference.Blog[] GetBlogs();
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface IBlogServiceChannel : TBlogServiceClient.TBlogServiceReference.IBlogService, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class BlogServiceClient : System.ServiceModel.ClientBase<TBlogServiceClient.TBlogServiceReference.IBlogService>, TBlogServiceClient.TBlogServiceReference.IBlogService {
        
        public BlogServiceClient() {
        }
        
        public BlogServiceClient(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public BlogServiceClient(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public BlogServiceClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public BlogServiceClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        public TBlogServiceClient.TBlogServiceReference.Blog[] GetBlogs() {
            return base.Channel.GetBlogs();
        }
    }
}
