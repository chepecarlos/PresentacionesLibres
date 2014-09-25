import android.bluetooth.BluetoothAdapter;

BluetoothAdapter bluetooth = BluetoothAdapter.getDefaultAdapter();

void setup() {
  orientation(LANDSCAPE);
}

void draw() {
  if (bluetooth.isEnabled()) {
    background(0, 255, 0);
  } else {
    background(255, 0, 0);
  }
}

