using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace MUXControlsTestApp.RadioButtonsTestObjects
{
    public class Item
    {
        public string Name;
    }

    public class TestViewModel : INotifyPropertyChanged
    {

        public List<Item> Items = new List<Item>() {
            new Item(){ Name="Item 1" },
            new Item(){ Name="Item 2" },
            new Item(){ Name="Item 3" },
            new Item(){ Name="Item 4" },
        };

        public Item SelectedItem;

        public int SelectedItemIndex;

        public TestViewModel()
        {
            SelectedItem = Items[0];
            SelectedItemIndex = 0;
        }


        public void ResetCollection()
        {
            Items = new List<Item>() {
                new Item(){ Name="Item 11" },
                new Item(){ Name="Item 12" },
                new Item(){ Name="Item 13" },
            };
            PropertyChanged.Invoke(this, new PropertyChangedEventArgs(nameof(Items)));

            SelectedItem = Items[0];
            PropertyChanged.Invoke(this, new PropertyChangedEventArgs(nameof(SelectedItem)));

            SelectedItemIndex = 0;
            PropertyChanged.Invoke(this, new PropertyChangedEventArgs(nameof(SelectedItemIndex)));
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}
